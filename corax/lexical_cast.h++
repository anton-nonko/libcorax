///\addtogroup string
///\{

/**
\defgroup lexical_cast lexical_cast
\todo Write documentation.
*////\{

#pragma once

#include <boost/lexical_cast.hpp>
#include "config.h"
#include "optional.h++"

namespace corax {
///\cond
	using boost::lexical_cast;
	using boost::bad_lexical_cast;
///\endcond

	///123
	template<class T, class S>
	inline T lexical_cast_noexcept(const S& source, T&& fallback) noexcept {
#if __CORAX_BOOST_AT_LEAST(1,56,0)
		using boost::conversion::try_lexical_convert;
		T target;
		return try_lexical_convert(source, target) ? target : fallback;
#else
		try {
			return lexical_cast<T>(source);
		} catch(...) {};

		return fallback;
#endif
	};

	template<class T, class S>
	inline optional<T> lexical_cast_optional(const S& source) noexcept {
#if __CORAX_BOOST_AT_LEAST(1,56,0)
		using boost::conversion::try_lexical_convert;
		optional<T> target;
		return
			boost::conversion::try_lexical_convert(source, *target) ? target : {};
#else
		try {
			return make_optional(lexical_cast<T>(source));
		} catch(...) {};

		return {};
#endif
	};
}; //corax

///\} //lexical_cast
///\} //string
