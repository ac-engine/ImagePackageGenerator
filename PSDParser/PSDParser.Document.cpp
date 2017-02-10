
#include "PSDParser.h"

namespace PSDParser
{
	Document::Document()
	{

	}


	Document::~Document()
	{
		backgroundLayer.reset();
		layers.clear();

		layersNative.reset();
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

	bool Document::Load(const void* data, int32_t size)
	{
		data_.resize(size);
		memcpy(data_.data(), data, size);

		buffer = psdBufferCreate((uint8_t*)data_.data(), size);
		document = psdDocumentCreate();
		psdDocumentParse(document, buffer);
		psdDocumentExtractImage(document);

		layersNative =std::make_shared<Layers>(psdDocumentGetAllLayers(document, &layerCount));

		layers.resize(layerCount);

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
		if (layerCount == 0) return 1;

		return layerCount;
	}

	std::shared_ptr<Layer> Document::GetLayer(int32_t index)
	{
		if (layerCount == 0 && index == 0)
		{
			if (backgroundLayer == nullptr)
			{
				backgroundLayer = std::make_shared<Layer>(this, document);
			}

			return backgroundLayer;
		}

		if (index < 0) return nullptr;
		if (index >= GetLayerCount()) return nullptr;

		if (layers[index] == nullptr)
		{
			layers[index] = std::make_shared<Layer>(this, layersNative->GetPointer()[index]);
		}

		return layers[index];
	}

	size_t Document::GetDepth()
	{
		return psdHeaderGetDepth(psdDocumentGetHeader(document));
	}

}