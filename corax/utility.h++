///\addtogroup fundamentals
///\{

#pragma once

#include <functional>
#include <utility>
#include "config.h"

namespace corax {

using std::size_t;

using std::forward;
using std::copy;
using std::move;

template<size_t I, class T>
constexpr auto get(T&& value) -> decltype(std::get<I>(forward<T&&>(value))) {
	return std::get<I>(forward<T&&>(value));
};

#if __CORAX_CXX14
template<class T, class U>
constexpr auto get(U&& value) -> decltype(std::get<T>(forward<U&&>(value))) {
	return std::get<T>(forward<U&&>(value));
};
#endif

}; //corax

///\} //fundamentals
