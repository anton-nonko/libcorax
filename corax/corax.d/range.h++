/**
\addtogroup fundamentals \{
\defgroup range
\{
*/

#pragma once

#include <boost/range/as_array.hpp>
#include <boost/range/iterator_range.hpp>
#include "utility.h++"

namespace corax {

using std::begin;
using std::end;

using boost::as_array;
using boost::iterator_range;
using boost::make_iterator_range;

template<class T>
inline auto as_range(T&& value) -> decltype(as_array(forward<T&&>(value))) {
	return as_array(forward<T&&>(value));
};

}; //corax

///\} //range
///\} //fundamentals
