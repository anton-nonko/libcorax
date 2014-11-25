///\addtogroup fundamentals
///\{

#pragma once

#include <tuple>
#include "config.h"
#include "type_list.h++"
#include "type_traits.h++"
#include "utility.h++"

namespace corax {

using std::tuple;
using std::make_tuple;

#if !__CORAX_CXX14
	#define DECL(modifier)                                                       \
		template<class T, class... List>                                           \
		constexpr T modifier get(tuple<List...> modifier tuple) {                  \
			static_assert(                                                           \
				type_list::count<T, List...>::value == 1,                              \
				"Zero or more than one member"                                         \
			);                                                                       \
			                                                                         \
			return get<type_list::find<T, List...>::value>(tuple);                   \
		};                                                                         \
		                                                                           \
		template<class T, class... List>                                           \
		constexpr                                                                  \
		typename enable_if<type_list::count<T, List...>() == 0, T modifier>::type  \
		get(tuple<List...> modifier tuple, T modifier fallback) {                  \
			return fallback;                                                         \
		};                                                                         \
		                                                                           \
		template<class T, class... List>                                           \
		constexpr                                                                  \
		typename enable_if<type_list::count<T, List...>() == 1, T modifier>::type  \
		get(tuple<List...> modifier tuple, T modifier fallback) {                  \
			return get<type_list::find<T, List...>()>(tuple);                        \
		}

	DECL(&);
	DECL(&&);
	DECL(const &);

	#undef DECL
#endif

}; //corax

///\} //fundamentals
