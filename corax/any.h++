///\addtogroup fundamentals
///\{

/**
\defgroup any any
\brief
	Adoptment of either [std::any] or [Boost.Any] to \ref corax namespace to ease
	usage.
[std::any]:  http://www.open-std.org/JTC1/sc22/WG21/docs/papers/2013/n3804.html
[Boost.Any]: http://www.boost.org/doc/libs/release/libs/any

This is used until `std::any` is not widely supported. To explicitly choose
version to use define \ref CORAX_ANY_BACKEND (should be either `std` or `boost`)
with a compiler flag. File content may be treated as follows:
\code
	namespace corax {
		namespace ns = CORAX_OPTIONAL_BACKEND;

		using ns::any;
		using ns::any_cast;
		using ns::bad_any_cast;
	};
\endcode
\see
[<experimental/any>](http://www.open-std.org/JTC1/sc22/WG21/docs/papers/2013/
n3804.html#synopsis)
[<boost/any.hpp>](http://www.boost.org/doc/libs/release/doc/html/any/
reference.html#header.boost.any_hpp)
*////\{

#pragma once

#include "config.h"

///\cond
#define std   1
#define boost 2
///\endcond

#if CORAX_ANY_BACKEND == std
	#define __CORAX_ANY_BACKEND_HEADER    <any>
	#define __CORAX_ANY_BACKEND_NAMESPACE std

#elif CORAX_ANY_BACKEND == boost
	#define __CORAX_ANY_BACKEND_HEADER    <boost/any.hpp>
	#define __CORAX_ANY_BACKEND_NAMESPACE boost

#else
	#error "Only 'std' or 'boost' may be used as CORAX_ANY_BACKEND value"

#endif

///\cond
#undef boost
#undef std
///\endcond

#include __CORAX_ANY_BACKEND_HEADER

///\cond
namespace corax {

using __CORAX_ANY_BACKEND_NAMESPACE::any;
using __CORAX_ANY_BACKEND_NAMESPACE::any_cast;
using __CORAX_ANY_BACKEND_NAMESPACE::bad_any_cast;

}; //corax
///\endcond

///\} //any
///\} //fundamentals
