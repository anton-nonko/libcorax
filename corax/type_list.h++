///\addtogroup generic
///\{

/**
\defgroup type_list Type List
\todo Write documentation.
*////\{

#pragma once

#include "type_traits.h++"

namespace corax {

namespace type_list {

template<class... List>
struct size {
	enum {value = sizeof...(List)};
};

template<class T, class... List>
class count;

template<class T>
struct count<T> {
	enum {value = 0};
};

template<class T, class Head, class... Tail>
struct count<T, Head, Tail...> {
	enum {value = is_same<T, Head>::value + count<T, Tail...>::value};
};

template<class T, class... List>
class find;

template<class T>
struct find<T> {
	enum {value = 0};
};

template<class T, class Head, class... Tail>
struct find<T, Head, Tail...> {
	enum {
		value = is_same<T, Head>::value ? 0 : find<T, Tail...>::value + 1
	};
};

}; //type_list

}; //corax

///\} //type_list
///\} //generic
