
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory>
#include <vector>
#include <string>
#include <string.h>

namespace PSDParser
{
	class Document;
	class Layer;

#if _WIN32
	typedef wchar_t uchar;
#else
	typedef char16_t uchar;
#endif
}