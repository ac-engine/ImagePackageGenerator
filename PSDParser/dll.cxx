/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.6
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#define SWIGCSHARP


#ifdef __cplusplus
/* SwigValueWrapper is described in swig.swg */
template<typename T> class SwigValueWrapper {
  struct SwigMovePointer {
    T *ptr;
    SwigMovePointer(T *p) : ptr(p) { }
    ~SwigMovePointer() { delete ptr; }
    SwigMovePointer& operator=(SwigMovePointer& rhs) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = rhs.ptr; rhs.ptr = 0; return *this; }
  } pointer;
  SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
  SwigValueWrapper(const SwigValueWrapper<T>& rhs);
public:
  SwigValueWrapper() : pointer(0) { }
  SwigValueWrapper& operator=(const T& t) { SwigMovePointer tmp(new T(t)); pointer = tmp; return *this; }
  operator T&() const { return *pointer.ptr; }
  T *operator&() { return pointer.ptr; }
};

template <typename T> T SwigValueInit() {
  return T();
}
#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif

/* Deal with Apple's deprecated 'AssertMacros.h' from Carbon-framework */
#if defined(__APPLE__) && !defined(__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES)
# define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0
#endif

/* Intel's compiler complains if a variable which was never initialised is
 * cast to void, which is a common idiom which we use to indicate that we
 * are aware a variable isn't used.  So we just silence that warning.
 * See: https://github.com/swig/swig/issues/192 for more discussion.
 */
#ifdef __INTEL_COMPILER
# pragma warning disable 592
#endif


#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/* Support for throwing C# exceptions from C/C++. There are two types: 
 * Exceptions that take a message and ArgumentExceptions that take a message and a parameter name. */
typedef enum {
  SWIG_CSharpApplicationException,
  SWIG_CSharpArithmeticException,
  SWIG_CSharpDivideByZeroException,
  SWIG_CSharpIndexOutOfRangeException,
  SWIG_CSharpInvalidCastException,
  SWIG_CSharpInvalidOperationException,
  SWIG_CSharpIOException,
  SWIG_CSharpNullReferenceException,
  SWIG_CSharpOutOfMemoryException,
  SWIG_CSharpOverflowException,
  SWIG_CSharpSystemException
} SWIG_CSharpExceptionCodes;

typedef enum {
  SWIG_CSharpArgumentException,
  SWIG_CSharpArgumentNullException,
  SWIG_CSharpArgumentOutOfRangeException
} SWIG_CSharpExceptionArgumentCodes;

typedef void (SWIGSTDCALL* SWIG_CSharpExceptionCallback_t)(const char *);
typedef void (SWIGSTDCALL* SWIG_CSharpExceptionArgumentCallback_t)(const char *, const char *);

typedef struct {
  SWIG_CSharpExceptionCodes code;
  SWIG_CSharpExceptionCallback_t callback;
} SWIG_CSharpException_t;

typedef struct {
  SWIG_CSharpExceptionArgumentCodes code;
  SWIG_CSharpExceptionArgumentCallback_t callback;
} SWIG_CSharpExceptionArgument_t;

static SWIG_CSharpException_t SWIG_csharp_exceptions[] = {
  { SWIG_CSharpApplicationException, NULL },
  { SWIG_CSharpArithmeticException, NULL },
  { SWIG_CSharpDivideByZeroException, NULL },
  { SWIG_CSharpIndexOutOfRangeException, NULL },
  { SWIG_CSharpInvalidCastException, NULL },
  { SWIG_CSharpInvalidOperationException, NULL },
  { SWIG_CSharpIOException, NULL },
  { SWIG_CSharpNullReferenceException, NULL },
  { SWIG_CSharpOutOfMemoryException, NULL },
  { SWIG_CSharpOverflowException, NULL },
  { SWIG_CSharpSystemException, NULL }
};

static SWIG_CSharpExceptionArgument_t SWIG_csharp_exceptions_argument[] = {
  { SWIG_CSharpArgumentException, NULL },
  { SWIG_CSharpArgumentNullException, NULL },
  { SWIG_CSharpArgumentOutOfRangeException, NULL }
};

static void SWIGUNUSED SWIG_CSharpSetPendingException(SWIG_CSharpExceptionCodes code, const char *msg) {
  SWIG_CSharpExceptionCallback_t callback = SWIG_csharp_exceptions[SWIG_CSharpApplicationException].callback;
  if ((size_t)code < sizeof(SWIG_csharp_exceptions)/sizeof(SWIG_CSharpException_t)) {
    callback = SWIG_csharp_exceptions[code].callback;
  }
  callback(msg);
}

static void SWIGUNUSED SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpExceptionArgumentCodes code, const char *msg, const char *param_name) {
  SWIG_CSharpExceptionArgumentCallback_t callback = SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentException].callback;
  if ((size_t)code < sizeof(SWIG_csharp_exceptions_argument)/sizeof(SWIG_CSharpExceptionArgument_t)) {
    callback = SWIG_csharp_exceptions_argument[code].callback;
  }
  callback(msg, param_name);
}


#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterExceptionCallbacks_PSDParser(
                                                SWIG_CSharpExceptionCallback_t applicationCallback,
                                                SWIG_CSharpExceptionCallback_t arithmeticCallback,
                                                SWIG_CSharpExceptionCallback_t divideByZeroCallback, 
                                                SWIG_CSharpExceptionCallback_t indexOutOfRangeCallback, 
                                                SWIG_CSharpExceptionCallback_t invalidCastCallback,
                                                SWIG_CSharpExceptionCallback_t invalidOperationCallback,
                                                SWIG_CSharpExceptionCallback_t ioCallback,
                                                SWIG_CSharpExceptionCallback_t nullReferenceCallback,
                                                SWIG_CSharpExceptionCallback_t outOfMemoryCallback, 
                                                SWIG_CSharpExceptionCallback_t overflowCallback, 
                                                SWIG_CSharpExceptionCallback_t systemCallback) {
  SWIG_csharp_exceptions[SWIG_CSharpApplicationException].callback = applicationCallback;
  SWIG_csharp_exceptions[SWIG_CSharpArithmeticException].callback = arithmeticCallback;
  SWIG_csharp_exceptions[SWIG_CSharpDivideByZeroException].callback = divideByZeroCallback;
  SWIG_csharp_exceptions[SWIG_CSharpIndexOutOfRangeException].callback = indexOutOfRangeCallback;
  SWIG_csharp_exceptions[SWIG_CSharpInvalidCastException].callback = invalidCastCallback;
  SWIG_csharp_exceptions[SWIG_CSharpInvalidOperationException].callback = invalidOperationCallback;
  SWIG_csharp_exceptions[SWIG_CSharpIOException].callback = ioCallback;
  SWIG_csharp_exceptions[SWIG_CSharpNullReferenceException].callback = nullReferenceCallback;
  SWIG_csharp_exceptions[SWIG_CSharpOutOfMemoryException].callback = outOfMemoryCallback;
  SWIG_csharp_exceptions[SWIG_CSharpOverflowException].callback = overflowCallback;
  SWIG_csharp_exceptions[SWIG_CSharpSystemException].callback = systemCallback;
}

#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterExceptionArgumentCallbacks_PSDParser(
                                                SWIG_CSharpExceptionArgumentCallback_t argumentCallback,
                                                SWIG_CSharpExceptionArgumentCallback_t argumentNullCallback,
                                                SWIG_CSharpExceptionArgumentCallback_t argumentOutOfRangeCallback) {
  SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentException].callback = argumentCallback;
  SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentNullException].callback = argumentNullCallback;
  SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentOutOfRangeException].callback = argumentOutOfRangeCallback;
}


/* Callback for returning strings to C# without leaking memory */
typedef char * (SWIGSTDCALL* SWIG_CSharpStringHelperCallback)(const char *);
static SWIG_CSharpStringHelperCallback SWIG_csharp_string_callback = NULL;


#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterStringCallback_PSDParser(SWIG_CSharpStringHelperCallback callback) {
  SWIG_csharp_string_callback = callback;
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, msg, ""); return nullreturn; } else


/* Callback for returning strings to C# without leaking memory */

#include <stdint.h>
#include <string>

namespace PSDParser
{
#ifdef _WIN32
typedef wchar_t uchar;
#else 
typedef char16_t uchar;
#endif
};

typedef void * (SWIGSTDCALL* SWIG_CSharpWStringHelperCallback)(const ::PSDParser::uchar *);
static SWIG_CSharpWStringHelperCallback SWIG_csharp_wstring_callback = NULL;


#ifdef __cplusplus
extern "C"
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterWStringCallback_PSDParser(SWIG_CSharpWStringHelperCallback callback) {
  SWIG_csharp_wstring_callback = callback;
}


#include "PSDParser.h"


#include <stdint.h>		// Use the C99 official header


struct SWIG_null_deleter {
  void operator() (void const *) const {
  }
};
#define SWIG_NO_NULL_DELETER_0 , SWIG_null_deleter()
#define SWIG_NO_NULL_DELETER_1
#define SWIG_NO_NULL_DELETER_SWIG_POINTER_NEW
#define SWIG_NO_NULL_DELETER_SWIG_POINTER_OWN


#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT void SWIGSTDCALL CSharp_Rect_Top_set(void * jarg1, int jarg2) {
  PSDParser::Rect *arg1 = (PSDParser::Rect *) 0 ;
  int32_t arg2 ;
  
  arg1 = (PSDParser::Rect *)jarg1; 
  arg2 = (int32_t)jarg2; 
  if (arg1) (arg1)->Top = arg2;
}


SWIGEXPORT int SWIGSTDCALL CSharp_Rect_Top_get(void * jarg1) {
  int jresult ;
  PSDParser::Rect *arg1 = (PSDParser::Rect *) 0 ;
  int32_t result;
  
  arg1 = (PSDParser::Rect *)jarg1; 
  result = (int32_t) ((arg1)->Top);
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_Rect_Left_set(void * jarg1, int jarg2) {
  PSDParser::Rect *arg1 = (PSDParser::Rect *) 0 ;
  int32_t arg2 ;
  
  arg1 = (PSDParser::Rect *)jarg1; 
  arg2 = (int32_t)jarg2; 
  if (arg1) (arg1)->Left = arg2;
}


SWIGEXPORT int SWIGSTDCALL CSharp_Rect_Left_get(void * jarg1) {
  int jresult ;
  PSDParser::Rect *arg1 = (PSDParser::Rect *) 0 ;
  int32_t result;
  
  arg1 = (PSDParser::Rect *)jarg1; 
  result = (int32_t) ((arg1)->Left);
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_Rect_Bottom_set(void * jarg1, int jarg2) {
  PSDParser::Rect *arg1 = (PSDParser::Rect *) 0 ;
  int32_t arg2 ;
  
  arg1 = (PSDParser::Rect *)jarg1; 
  arg2 = (int32_t)jarg2; 
  if (arg1) (arg1)->Bottom = arg2;
}


SWIGEXPORT int SWIGSTDCALL CSharp_Rect_Bottom_get(void * jarg1) {
  int jresult ;
  PSDParser::Rect *arg1 = (PSDParser::Rect *) 0 ;
  int32_t result;
  
  arg1 = (PSDParser::Rect *)jarg1; 
  result = (int32_t) ((arg1)->Bottom);
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_Rect_Right_set(void * jarg1, int jarg2) {
  PSDParser::Rect *arg1 = (PSDParser::Rect *) 0 ;
  int32_t arg2 ;
  
  arg1 = (PSDParser::Rect *)jarg1; 
  arg2 = (int32_t)jarg2; 
  if (arg1) (arg1)->Right = arg2;
}


SWIGEXPORT int SWIGSTDCALL CSharp_Rect_Right_get(void * jarg1) {
  int jresult ;
  PSDParser::Rect *arg1 = (PSDParser::Rect *) 0 ;
  int32_t result;
  
  arg1 = (PSDParser::Rect *)jarg1; 
  result = (int32_t) ((arg1)->Right);
  jresult = result; 
  return jresult;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_new_Rect() {
  void * jresult ;
  PSDParser::Rect *result = 0 ;
  
  result = (PSDParser::Rect *)new PSDParser::Rect();
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_delete_Rect(void * jarg1) {
  PSDParser::Rect *arg1 = (PSDParser::Rect *) 0 ;
  
  arg1 = (PSDParser::Rect *)jarg1; 
  delete arg1;
}


SWIGEXPORT void SWIGSTDCALL CSharp_delete_Layer(void * jarg1) {
  PSDParser::Layer *arg1 = (PSDParser::Layer *) 0 ;
  std::shared_ptr< PSDParser::Layer > *smartarg1 = 0 ;
  
  
  smartarg1 = (std::shared_ptr<  PSDParser::Layer > *)jarg1;
  arg1 = (PSDParser::Layer *)(smartarg1 ? smartarg1->get() : 0); 
  (void)arg1; delete smartarg1;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_Layer_GetData(void * jarg1) {
  void * jresult ;
  PSDParser::Layer *arg1 = (PSDParser::Layer *) 0 ;
  std::shared_ptr< PSDParser::Layer > *smartarg1 = 0 ;
  void *result = 0 ;
  
  
  smartarg1 = (std::shared_ptr<  PSDParser::Layer > *)jarg1;
  arg1 = (PSDParser::Layer *)(smartarg1 ? smartarg1->get() : 0); 
  result = (void *)(arg1)->GetData();
  {
    jresult = result; 
  }
  return jresult;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_Layer_GetRect(void * jarg1) {
  void * jresult ;
  PSDParser::Layer *arg1 = (PSDParser::Layer *) 0 ;
  std::shared_ptr< PSDParser::Layer > *smartarg1 = 0 ;
  PSDParser::Rect result;
  
  
  smartarg1 = (std::shared_ptr<  PSDParser::Layer > *)jarg1;
  arg1 = (PSDParser::Layer *)(smartarg1 ? smartarg1->get() : 0); 
  result = (arg1)->GetRect();
  jresult = new PSDParser::Rect((const PSDParser::Rect &)result); 
  return jresult;
}


SWIGEXPORT ::PSDParser::uchar * SWIGSTDCALL CSharp_Layer_GetName(void * jarg1) {
  ::PSDParser::uchar * jresult ;
  PSDParser::Layer *arg1 = (PSDParser::Layer *) 0 ;
  std::shared_ptr< PSDParser::Layer const > *smartarg1 = 0 ;
  PSDParser::uchar *result = 0 ;
  
  
  smartarg1 = (std::shared_ptr< const PSDParser::Layer > *)jarg1;
  arg1 = (PSDParser::Layer *)(smartarg1 ? smartarg1->get() : 0); 
  result = (PSDParser::uchar *)((PSDParser::Layer const *)arg1)->GetName();
  jresult = (::PSDParser::uchar *)result; 
  return jresult;
}


SWIGEXPORT unsigned long SWIGSTDCALL CSharp_Layer_GetSrtideLength(void * jarg1) {
  unsigned long jresult ;
  PSDParser::Layer *arg1 = (PSDParser::Layer *) 0 ;
  std::shared_ptr< PSDParser::Layer > *smartarg1 = 0 ;
  size_t result;
  
  
  smartarg1 = (std::shared_ptr<  PSDParser::Layer > *)jarg1;
  arg1 = (PSDParser::Layer *)(smartarg1 ? smartarg1->get() : 0); 
  result = (arg1)->GetSrtideLength();
  jresult = (unsigned long)result; 
  return jresult;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_new_Layer() {
  void * jresult ;
  PSDParser::Layer *result = 0 ;
  
  result = (PSDParser::Layer *)new PSDParser::Layer();
  
  jresult = result ? new std::shared_ptr<  PSDParser::Layer >(result SWIG_NO_NULL_DELETER_1) : 0;
  
  return jresult;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_new_Document() {
  void * jresult ;
  PSDParser::Document *result = 0 ;
  
  result = (PSDParser::Document *)new PSDParser::Document();
  
  jresult = result ? new std::shared_ptr<  PSDParser::Document >(result SWIG_NO_NULL_DELETER_1) : 0;
  
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_delete_Document(void * jarg1) {
  PSDParser::Document *arg1 = (PSDParser::Document *) 0 ;
  std::shared_ptr< PSDParser::Document > *smartarg1 = 0 ;
  
  
  smartarg1 = (std::shared_ptr<  PSDParser::Document > *)jarg1;
  arg1 = (PSDParser::Document *)(smartarg1 ? smartarg1->get() : 0); 
  (void)arg1; delete smartarg1;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_Document_Create(void * jarg1, int jarg2) {
  void * jresult ;
  void *arg1 = (void *) 0 ;
  int32_t arg2 ;
  std::shared_ptr< PSDParser::Document > result;
  
  {
    arg1 = jarg1; 
  }
  arg2 = (int32_t)jarg2; 
  result = PSDParser::Document::Create(arg1,arg2);
  jresult = result ? new std::shared_ptr< PSDParser::Document >(result) : 0; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_Document_GetLayerCount(void * jarg1) {
  int jresult ;
  PSDParser::Document *arg1 = (PSDParser::Document *) 0 ;
  std::shared_ptr< PSDParser::Document > *smartarg1 = 0 ;
  int32_t result;
  
  
  smartarg1 = (std::shared_ptr<  PSDParser::Document > *)jarg1;
  arg1 = (PSDParser::Document *)(smartarg1 ? smartarg1->get() : 0); 
  result = (int32_t)(arg1)->GetLayerCount();
  jresult = result; 
  return jresult;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_Document_GetLayer(void * jarg1, int jarg2) {
  void * jresult ;
  PSDParser::Document *arg1 = (PSDParser::Document *) 0 ;
  int32_t arg2 ;
  std::shared_ptr< PSDParser::Document > *smartarg1 = 0 ;
  std::shared_ptr< PSDParser::Layer > result;
  
  
  smartarg1 = (std::shared_ptr<  PSDParser::Document > *)jarg1;
  arg1 = (PSDParser::Document *)(smartarg1 ? smartarg1->get() : 0); 
  arg2 = (int32_t)jarg2; 
  result = (arg1)->GetLayer(arg2);
  jresult = result ? new std::shared_ptr< PSDParser::Layer >(result) : 0; 
  return jresult;
}


SWIGEXPORT unsigned long SWIGSTDCALL CSharp_Document_GetDepth(void * jarg1) {
  unsigned long jresult ;
  PSDParser::Document *arg1 = (PSDParser::Document *) 0 ;
  std::shared_ptr< PSDParser::Document > *smartarg1 = 0 ;
  size_t result;
  
  
  smartarg1 = (std::shared_ptr<  PSDParser::Document > *)jarg1;
  arg1 = (PSDParser::Document *)(smartarg1 ? smartarg1->get() : 0); 
  result = (arg1)->GetDepth();
  jresult = (unsigned long)result; 
  return jresult;
}


#ifdef __cplusplus
}
#endif

