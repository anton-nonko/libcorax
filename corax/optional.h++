///\addtogroup fundamentals
///\{

/**
\defgroup optional optional
\brief
	Adoptment of either [std::optional] or [Boost.Optional] to \ref corax
	namespace to ease usage.
[std::optional]:
	http://www.open-std.org/JTC1/sc22/WG21/docs/papers/2013/n3793.html
[Boost.Optional]: http://www.boost.org/doc/libs/release/libs/optional

This is used until `std::optional` is not widely supported. To explicitly
choose version to use define \ref CORAX_OPTIONAL_BACKEND (should be either `std`
or `boost`) with a compiler flag. File content may be treated as follows:
\code
	namespace corax {
		namespace ns = CORAX_OPTIONAL_BACKEND;

		using ns::optional;
		using ns::make_optional;
	};
\endcode
\see
[<experimental/optional>](http://en.cppreference.com/w/cpp/header/experimental/
optional)
[<boost/optional.hpp>](http://www.boost.org/doc/libs/release/libs/optional/doc/
html/optional/reference.html#boost_optional.reference.synopsis)
*////\{

#pragma once

#include "config.h"

///\cond
#define std   1
#define boost 2
///\endcond

#define __CORAX_OPTIONAL_BACKEND_STD   0
#define __CORAX_OPTIONAL_BACKEND_BOOST 0

#if CORAX_OPTIONAL_BACKEND == std
	#undef  __CORAX_OPTIONAL_BACKEND_STD
	#define __CORAX_OPTIONAL_BACKEND_STD       1

	#define __CORAX_OPTIONAL_BACKEND_HEADER    <optional>
	#define __CORAX_OPTIONAL_BACKEND_NAMESPACE std

#elif CORAX_OPTIONAL_BACKEND == boost
	#undef  __CORAX_OPTIONAL_BACKEND_BOOST
	#define __CORAX_OPTIONAL_BACKEND_BOOST     1

	#define __CORAX_OPTIONAL_BACKEND_HEADER    <boost/optional.hpp>
	#define __CORAX_OPTIONAL_BACKEND_NAMESPACE boost

#else
	#error "Only `std` or `boost` may be used as CORAX_OPTIONAL_BACKEND value"

#endif

///\cond
#undef boost
#undef std
///\endcond

#include __CORAX_OPTIONAL_BACKEND_HEADER

///\cond
namespace corax {

using __CORAX_OPTIONAL_BACKEND_NAMESPACE::optional;
using __CORAX_OPTIONAL_BACKEND_NAMESPACE::make_optional;

#if __CORAX_OPTIONAL_BACKEND_BOOST
	using boost::none_t;
	using boost::none;

	typedef none_t nullopt_t;
	const nullopt_t& nullopt = none;

#else
	using std::nullopt_t;
	using std::nullopt;

	typedef nullopt_t none_t;
	const none_t& none = nullopt;

#endif

}; //corax
///\endcond

///\} //optional
///\} //fundamentals
