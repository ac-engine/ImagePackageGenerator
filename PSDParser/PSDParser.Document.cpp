
#include "PSDParser.h"

#if _WIN32
#include <Windows.h>
#endif

namespace PSDParser
{
	static int32_t Utf8ToUtf16(std::vector<int16_t> &dst, const int8_t* src)
	{
		int32_t code;
		int8_t c0, c1, c2;
		dst.resize(0);

		for (;;)
		{
			int16_t wc;

			c0 = *src++;
			if (c0 == '\0')
			{
				break;
			}
			// UTF8‚©‚çUTF16‚É•ÏŠ·
			code = (uint8_t)c0 >> 4;
			if (code <= 7)
			{
				// 8bit•¶Žš
				wc = c0;
			}
			else if (code >= 12 && code <= 13)
			{
				// 16bit•¶Žš
				c1 = *src++;
				wc = ((c0 & 0x1F) << 6) | (c1 & 0x3F);
			}
			else if (code == 14)
			{
				// 24bit•¶Žš
				c1 = *src++;
				c2 = *src++;
				wc = ((c0 & 0x0F) << 12) | ((c1 & 0x3F) << 6) | (c2 & 0x3F);
			}
			else
			{
				continue;
			}
			dst.push_back(wc);
		}
		dst.push_back(0);
		return static_cast<int32_t>(dst.size()) - 1;
	}

	static void ParseDocument(psd_document_t* document, int32_t depth, std::basic_string<uchar>& name, Rect& rect, std::vector<uint8_t>& data)
	{
		{
#if  _WIN32
			name = L"Background(All)";
#else
			name = u"Background(All)";
#endif
		}

		{
			const psd_header_t* header = psdDocumentGetHeader(document);
			psd_size_t size = psdHeaderGetSize(header);

			rect.Top = 0;
			rect.Bottom = size.rows;
			rect.Left = 0;
			rect.Right = size.columns;
		}

		{
			const psd_header_t* header = psdDocumentGetHeader(document);
			psd_size_t size = psdHeaderGetSize(header);

			auto stride = psdSizeGetStrideLength(&size, depth) * 4;

			data.resize(size.columns * size.rows * 4);
			auto dst = (uint8_t*)data.data();
			auto src = (uint8_t*)psdImageGetPixelData(psdDocumentGetImage(document));

			for (int y = 0; y < size.rows; y++)
			{
				for (int x = 0; x < size.columns; x++)
				{
					dst[(x + y * size.columns) * 4 + 0] = src[x * 4 + y * stride + 0];
					dst[(x + y * size.columns) * 4 + 1] = src[x * 4 + y * stride + 1];
					dst[(x + y * size.columns) * 4 + 2] = src[x * 4 + y * stride + 2];
					dst[(x + y * size.columns) * 4 + 3] = src[x * 4 + y * stride + 3];
				}
			}
		}
	}

	static void ParseLayer(psd_layer_t* layer, int32_t depth, std::basic_string<uchar>& name, Rect& rect, std::vector<uint8_t>& data)
	{
		psdLayerExtract(layer);

		{
			auto uname = psdLayerGetName(layer);
			auto lname = psdLayerGetPascalName(layer);

			std::vector<int16_t> buf;
			if (strlen(uname) > 0)
			{
				for (int32_t i = 0;;)
				{
					char v[2];
					v[1] = uname[i + 0];
					v[0] = uname[i + 1];

					uchar c;
					memcpy(&c, v, 2);
					buf.push_back(c);

					if (c == 0) break;
					i += 2;
				}
			}
			else if (strlen(lname) > 0)
			{
#if _WIN32
				buf.resize(256);
				::MultiByteToWideChar(CP_ACP, 0, (LPCSTR)lname, -1, (LPWSTR)buf.data(), buf.size() * sizeof(uchar));
#else
				Utf8ToUtf16(buf, (const int8_t*)lname);
#endif
			}

			buf.push_back(0);

			name = (uchar*)buf.data();
		}

		// Rect
		{
			auto rect_ = psdLayerGetRect(layer);
			rect.Top = rect_.top;
			rect.Bottom = rect_.bottom;
			rect.Left = rect_.left;
			rect.Right = rect_.right;
		}
		
		// Data
		{
			psd_size_t size;
			auto rect_ = psdLayerGetRect(layer);
			size.columns = psdRectGetWidth(&rect_);
			size.rows = psdRectGetHeight(&rect_);

			auto stride = psdSizeGetStrideLength(&size, depth) * 4;

			data.resize(size.columns * size.rows * 4);
			auto dst = (uint8_t*)data.data();
			auto src = (uint8_t*)psdLayerGetPixelData(layer);

			for (int y = 0; y < size.rows; y++)
			{
				for (int x = 0; x < size.columns; x++)
				{
					dst[(x + y * size.columns) * 4 + 0] = src[x * 4 + y * stride + 0];
					dst[(x + y * size.columns) * 4 + 1] = src[x * 4 + y * stride + 1];
					dst[(x + y * size.columns) * 4 + 2] = src[x * 4 + y * stride + 2];
					dst[(x + y * size.columns) * 4 + 3] = src[x * 4 + y * stride + 3];
				}
			}
		}
	}

	Document::Document()
	{

	}


	Document::~Document()
	{
	}

	bool Document::Load(const void* data, int32_t size)
	{
		psd_document_t*	document = nullptr;
		psd_buffer_t*	buffer = nullptr;

		buffer = psdBufferCreate((uint8_t*)data, size);
		document = psdDocumentCreate();
		psdDocumentParse(document, buffer);
		psdDocumentExtractImage(document);

		colorDepth = psdHeaderGetDepth(psdDocumentGetHeader(document));

		psd_rsize_t layerCount = 0;
		auto nativeLayers = psdDocumentGetAllLayers(document, &layerCount);

		layers.resize(layerCount);

		for (int32_t i = 0; i < layerCount; i++)
		{
			auto nativeLayer = nativeLayers[i];

			std::basic_string<uchar> name;
			Rect rect;
			std::vector<uint8_t> data;

			ParseLayer(nativeLayer, colorDepth, name, rect, data);

			auto layer = std::make_shared<Layer>(data.data(), rect, name);
			layers[i] = layer;
		}

		free((void*)nativeLayers);

		if(layerCount == 0)
		{
			std::basic_string<uchar> name;
			Rect rect;
			std::vector<uint8_t> data;

			ParseDocument(document, colorDepth, name, rect, data);

			auto layer = std::make_shared<Layer>(data.data(), rect, name);

			layers.push_back(layer);
		}

		if (document != nullptr)
		{
			psdDocumentDestroy(document);
		}
		document = nullptr;

		if (buffer != nullptr)
		{
			psdBufferDestroy(buffer);
		}
		buffer = nullptr;

		return true;
	}

	std::shared_ptr<Document> Document::Create(const void* data, int32_t size)
	{
		auto doc = std::make_shared<Document>();

		if (doc->Load(data, size))
		{
			return doc;
		}

		return nullptr;
	}

	int32_t Document::GetLayerCount()
	{
		return layers.size();
	}

	std::shared_ptr<Layer> Document::GetLayer(int32_t index)
	{
		if (index < 0) return nullptr;
		if (index >= GetLayerCount()) return nullptr;
		return layers[index];
	}

	size_t Document::GetDepth()
	{
		return colorDepth;
	}

}