
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
		std::basic_string<uchar>	name;
		std::vector<uint8_t>		data;
		Rect						area;

	public:

#if !SWIG
		Layer(const uint8_t* data, Rect area, std::basic_string<uchar> name)
		{
			auto width = area.Right - area.Left;
			auto height = area.Bottom - area.Top;

			this->data.resize(width * height * 4);
			memcpy(this->data.data(), data, this->data.size());

			this->area = area;
			this->name = name;
		}
#endif
		Layer() {}
		virtual ~Layer() {}

		const void* GetData()
		{
			return data.data();
		}

		Rect GetRect()
		{
			return area;
		}

		const uchar* GetName() const { return name.c_str(); }
	};

	class Document
		: public std::enable_shared_from_this<Document>
	{
	private:

		std::vector<std::shared_ptr<Layer>>	layers;
		int32_t						colorDepth = 0;
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

