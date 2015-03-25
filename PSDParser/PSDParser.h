
#pragma once

#include "psd/psd.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory>
#include <vector>
#include <string>


namespace PSDParser
{
	template <class T>
	void SafeAddRef(T& t)
	{
		if (t != NULL)
		{
			t->AddRef();
		}
	}

	template <class T>
	void SafeRelease(T& t)
	{
		if (t != NULL)
		{
			t->Release();
			t = NULL;
		}
	}

	class Document;
	class Layer;

	struct Rect
	{
		int32_t Top;
		int32_t Left;
		int32_t Bottom;
		int32_t Right;
	};

#if _WIN32
	typedef wchar_t uchar;
#else
	typedef char16_t uchar;
#endif

	class ReferenceObject
	{
	private:
		int32_t	reference = 1;
	
	public:
		ReferenceObject();
		virtual ~ReferenceObject();
		int32_t AddRef();
		int32_t Release();
	};

	class Layer
		: public ReferenceObject
	{
		friend class Document;

		Document*		doc = nullptr;
		psd_layer_t*	layer = nullptr;
		psd_document_t* document = nullptr;

		std::basic_string<uchar>	name;

		Layer(Document* doc, psd_layer_t* layer);

		Layer(Document* doc, psd_document_t* docment);

		virtual ~Layer();

	public:

		const void* GetData()
		{
			if (layer != nullptr)
			{
				return psdLayerGetPixelData(layer);
			}
			else
			{
				return psdImageGetPixelData(psdDocumentGetImage(document));
			}
		}

		Rect GetRect()
		{
			if (layer != nullptr)
			{
				auto rect = psdLayerGetRect(layer);
				Rect r;
				r.Top = rect.top;
				r.Bottom = rect.bottom;
				r.Left = rect.left;
				r.Right = rect.right;

				return r;
			}
			else
			{
				const psd_header_t *header = psdDocumentGetHeader(document);
				psd_size_t size = psdHeaderGetSize(header);

				Rect r;
				r.Top = 0;
				r.Bottom = size.rows;
				r.Left = 0;
				r.Right = size.columns;

				return r;
			}
		}

		const uchar* GetName() const { return name.c_str(); }

		size_t GetSrtideLength();
	};

	class Document
		: public ReferenceObject
	{
	private:

		class Layers
		{
			psd_layer_t *const * layers;
		public:
			Layers(psd_layer_t *const * layers)
				: layers(layers)
			{
			}

			virtual ~Layers()
			{
				free((void*) layers);
			}

			psd_layer_t *const * GetPointer() { return layers; }
		};

		std::vector<uint8_t>	data_;

		psd_document_t*	document = nullptr;
		psd_buffer_t*	buffer = nullptr;

		Layers*			layersNative = nullptr;
		psd_rsize_t		layerCount = 0;

		std::vector<Layer*>	layers;

		Layer*				backgroundLayer = nullptr;

		Document()
		{

		}

		virtual ~Document()
		{
			SafeRelease(backgroundLayer);

			for (size_t i = 0; i < layers.size(); i++)
			{
				SafeRelease(layers[i]);
			}
			layers.clear();

			if (layersNative != nullptr)
			{
				delete layersNative;
			}
			layersNative = nullptr;

			layerCount = 0;

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
		}

		bool Load(void* data, int32_t size)
		{
			data_.resize(size);
			memcpy(data_.data(), data, size);

			buffer = psdBufferCreate((uint8_t*) data_.data(), size);
			document = psdDocumentCreate();
			psdDocumentParse(document, buffer);
			psdDocumentExtractImage(document);

			layersNative = new Layers(psdDocumentGetAllLayers(document, &layerCount));

			layers.resize(layerCount);

			return true;
		}

	public:

		static Document* Create(void* data, int32_t size)
		{
			auto doc = new Document();

			if (doc->Load(data, size))
			{
				return doc;
			}
			
			doc->Release();

			return nullptr;
		}

		int32_t GetLayerCount() 
		{ 
			if (layerCount == 0) return 1;

			return layerCount;
		}

		Layer* GetLayer(int32_t index)
		{
			if (layerCount == 0 && index == 0)
			{
				if (backgroundLayer == nullptr)
				{
					backgroundLayer = new Layer(this, document);
				}

				return backgroundLayer;
			}

			if (index < 0) return nullptr;
			if (index >= GetLayerCount()) return nullptr;

			if (layers[index] == nullptr)
			{
				layers[index] = new Layer(this, layersNative->GetPointer()[index]);
			}

			return layers[index];
		}

		size_t GetDepth() { return psdHeaderGetDepth(psdDocumentGetHeader(document)); }

	};
}

