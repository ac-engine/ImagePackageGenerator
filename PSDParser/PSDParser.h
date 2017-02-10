
#pragma once

#include "PSDParser.Base.h"

#include "psd/psd.h"

namespace PSDParser
{
	struct Rect
	{
		int32_t Top;
		int32_t Left;
		int32_t Bottom;
		int32_t Right;
	};

	class Layer
		: public std::enable_shared_from_this<Layer>
	{
		friend class Document;

		Document*		doc = nullptr;
		psd_layer_t*	layer = nullptr;
		psd_document_t* document = nullptr;

		std::basic_string<uchar>	name;

	public:

#if !SWIG
		Layer(Document* doc, psd_layer_t* layer);

		Layer(Document* doc, psd_document_t* docment);
#endif

		virtual ~Layer();

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
		: public std::enable_shared_from_this<Document>
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

		std::shared_ptr<Layers>		layersNative = nullptr;
		psd_rsize_t		layerCount = 0;

		std::vector<std::shared_ptr<Layer>>	layers;

		std::shared_ptr<Layer>		backgroundLayer = nullptr;

	public:

		Document();

		virtual ~Document();

#if !SWIG
		bool Load(const void* data, int32_t size);
#endif

		static std::shared_ptr<Document> Create(const void* data, int32_t size);

		int32_t GetLayerCount();

		std::shared_ptr<Layer> GetLayer(int32_t index);

		size_t GetDepth();

	};
}

