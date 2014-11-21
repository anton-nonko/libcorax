///\addtogroup fundamentals
///\{

/**
\defgroup tdc Type Dependent Constants
\todo Write documentation.
\todo Add all available operators support.
*////\{

#pragma once

#include <boost/preprocessor.hpp>
#include "type_traits.h++"

///\cond
namespace corax  {
namespace tdc    {
namespace detail {

/*
Legenda:
	U ......... unary
	B ......... binary
	O/o ....... operator
	E/e ....... expression class
	F ......... forward declaration
	T, V, W ... generic types
*/

// Unary operators and corresponding expression classes
#define U \
	((~, compl_expr))

// Binary operators and corresponding expression classes
#define B \
	((|, bitor_expr))\
	((&, bitand_expr))

#define U_E_F(o, e) template<class> class e

#define U_E(o, e)                                                              \
	template<class T> struct e : public mixin<e<T>>{                             \
		template<class V> constexpr operator V() const {return o V{T{}};};         \
	}

#define U_O(o, e) constexpr e<T> operator o() {return {};}

#define B_E_F(o, e) template<class, class> class e

#define B_E(o, e)                                                              \
	template<class T, class V> struct e : public mixin<e<T, V>>{                 \
		constexpr e() = default;                                                   \
		                                                                           \
		constexpr e(V) {};                                                         \
		                                                                           \
		template<class W> constexpr operator W() const {return W{T{}} o W{V{}};};  \
	}

#define B_O(o, e)                                                              \
	template<class V>                                                            \
	constexpr                                                                    \
	typename conditional<is_base_of<mixin<V>, V>::value, e<T, V>, V>::type       \
	operator o(V v) {                                                            \
		return v;                                                                  \
	}

#define ITOR(r, macro, args) macro args;

#define DECL(decl)                                                             \
	BOOST_PP_SEQ_FOR_EACH(ITOR, U_##decl, U)                                     \
	BOOST_PP_SEQ_FOR_EACH(ITOR, B_##decl, B)

DECL(E_F)

template<class T> struct mixin {
	DECL(O)
};

DECL(E)

#undef ITOR
#undef DECL

#undef U_E_F
#undef U_E
#undef U_O
#undef B_E_F
#undef B_E
#undef B_O

#undef U
#undef B

}; //detail
}; //tdc
}; //corax
///\endcond

#define __corax_tdc(c)                                                         \
	struct __corax_tdc_class_##c :                                               \
		public ::corax::tdc::detail::mixin<__corax_tdc_class_##c>                  \
	{                                                                            \
		constexpr __corax_tdc_class_##c() = default;                               \
		template<class T> constexpr operator T();                                  \
	} constexpr c

#define __corax_tdc_cast(c, type, value)                                       \
	template<> constexpr decltype(c)::operator type() {return value;}

///\} //tdc
///\} //fundamentals
