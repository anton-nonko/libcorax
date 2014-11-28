#pragma once

#include <boost/config.hpp>
#include "system.h"

#define __CORAX_CXX11 0
#define __CORAX_CXX14 0

#if __CORAX_GCC
	#if __CORAX_GCC_AT_LEAST(4,7,0) && __cplusplus >= 201103L
		#undef  __CORAX_CXX11
		#define __CORAX_CXX11 1

	#elif defined __GXX_EXPERIMENTAL_CXX0X__
		#undef  __CORAX_CXX11
		#define __CORAX_CXX11 1

	#endif //__CORAX_GCC_AT_LEAST(4,7,0) && __cplusplus >= 201103L
#endif //__CORAX_GCC

#ifdef BOOST_NO_CXX11_HDR_THREAD
	#define __CORAX_CXX11_THREAD 0
#else
	#define __CORAX_CXX11_THREAD 1
#endif

#define __CORAX_CXX14_ANY      __CORAX_CXX14
#define __CORAX_CXX14_OPTIONAL __CORAX_CXX14
