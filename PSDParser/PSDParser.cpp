
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
			code = (uint8_t) c0 >> 4;
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

	Layer::Layer(Document* doc, psd_layer_t* layer)
		: doc(doc)
		, layer(layer)
	{
		psdLayerExtract(layer);

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
			//Utf8ToUtf16(buf, (const int8_t*) uname);
		}
		else 
		if (strlen(lname) > 0)
		{
#if _WIN32
			buf.resize(256);
			::MultiByteToWideChar(CP_ACP, 0, (LPCSTR)lname, -1, (LPWSTR)buf.data(), buf.size() * sizeof(uchar));
#else
			Utf8ToUtf16(buf, (const int8_t*) lname);
#endif
		}

		buf.push_back(0);

		name = (uchar*)buf.data();
	}

	Layer::Layer(Document* doc, psd_document_t* document)
		: doc(doc)
		, layer(nullptr)
		, document(document)
	{
#if _WIN32
		name = L"”wŒi";
#endif
	}

	Layer::~Layer()
	{

	}

	size_t Layer::GetSrtideLength()
	{
		if (layer != nullptr)
		{
			auto rect = psdLayerGetRect(layer);

			psd_size_t size;
			size.columns = psdRectGetWidth(&rect);
			size.rows = psdRectGetHeight(&rect);

			return psdSizeGetStrideLength(&size, doc->GetDepth()) * 4;
		}
		else
		{
			const psd_header_t* header = psdDocumentGetHeader(document);
			return psdHeaderGetStrideLength(header) * 4;
		}
	}

}
