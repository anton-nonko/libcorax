/**
\defgroup string
*////\{

#pragma once

#include <sstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include "utility.h++"

namespace corax {

using std::basic_string;
using std::string;

using std::basic_stringstream;
using std::stringstream;

using std::basic_ostringstream;
using std::ostringstream;

using std::basic_istringstream;
using std::istringstream;

namespace detail {

struct string_default {
	typedef string::value_type     value_type;
	typedef string::traits_type    traits_type;
	typedef string::allocator_type allocator_type;
};

template<class C, class T, class A>
basic_ostringstream<C, T, A>& make_string(
	basic_ostringstream<C, T, A>& stream
) {
	return stream;
};

template<class C, class T, class A, class Head, class... Tail>
basic_ostringstream<C, T, A>& make_string(
	basic_ostringstream<C, T, A>& stream, Head&& head, Tail&&... tail
) {
	stream << forward<Head&&>(head);
	return make_string(stream, forward<Tail&&>(tail)...);
};

}; //detail

template<
	class C = detail::string_default::value_type,
	class T = detail::string_default::traits_type,
	class A = detail::string_default::allocator_type,
	class... List
>
basic_string<C, T, A> make_string(List&&... list) {
	basic_ostringstream<C, T, A> stream;
	return detail::make_string(stream, forward<List&&>(list)...).str();
};

}; //corax

///\} //string
