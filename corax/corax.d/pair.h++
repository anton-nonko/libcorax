///\addtogroup fundamentals
///\{

#pragma once

#include <utility>
#include "config.h"
#include "utility.h++"

namespace corax {

using std::pair;
using std::make_pair;

#if !__CORAX_CXX14
	#define DECL(modifier)                                                       \
		template<class T, class U>                                                 \
		constexpr T modifier get(pair<T, U> modifier pair) {return pair.first;};   \
		                                                                           \
		template<class T, class U>                                                 \
		constexpr T modifier get(pair<U, T> modifier pair) {return pair.first;}

	DECL(&);
	DECL(&&);
	DECL(const &);

	#undef DECL
#endif

}; //corax

///\} //fundamentals
