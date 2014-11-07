///\addtogroup generic
///\{

/**
\defgroup integer integer
\brief
	Adoptment of [Boost.Integer] to \ref corax namespace to ease usage.
[Boost.Integer]:
	http://www.boost.org/doc/libs/release/libs/integer

File content may be treated as follows:
\code
	namespace corax {
		using boost::int_t;
		using boost::uint_t;
		using boost::int_max_value_t;
		using boost::int_min_value_t;
		using boost::uint_value_t;
	};
\endcode
\see
[<boost/integer_traits.hpp>](http://www.boost.org/doc/libs/release/libs/integer/
doc/html/boost_integer/traits.html)
[<boost/integer.hpp>](http://www.boost.org/doc/libs/release/libs/integer/doc/
html/boost_integer/integer.html)
[<boost/integer_mask.hpp>](http://www.boost.org/doc/libs/release/libs/integer/
doc/html/boost_integer/mask.html)
*////\{

#pragma once

#include <boost/integer.hpp>
#include "config.h"

///\cond
namespace corax {

using boost::int_t;
using boost::uint_t;
using boost::int_max_value_t;
using boost::int_min_value_t;
using boost::uint_value_t;

}; //corax
///\endcond

///\} //integer
///\} //fundamentals
