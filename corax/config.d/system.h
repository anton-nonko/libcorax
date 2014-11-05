#pragma once

#include <boost/config.hpp>
#include <boost/version.hpp>

#define __CORAX_GCC                 0
#define __CORAX_GCC_AT_LEAST(...)   0

#define __CORAX_CLANG               0
#define __CORAX_CLANG_AT_LEAST(...) 0

#define __CORAX_INTEL               0
#define __CORAX_INTEL_AT_LEAST(...) 0

#define __CORAX_MSVC                0
#define __CORAX_MSVC_AT_LEAST(...)  0

#define __CORAX_POSIX               0
#define __CORAX_UNIX                0
#define __CORAX_LINUX               0

#define __CORAX_BOOST_AT_LEAST(major, minor, patchlevel)                       \
	(BOOST_VERSION >= (major) * 100000 + (minor) * 100 + (patchlevel))

#ifdef BOOST_GCC
	#undef  __CORAX_GCC
	#define __CORAX_GCC BOOST_GCC

	#undef  __CORAX_GCC_AT_LEAST
	#define __CORAX_GCC_AT_LEAST(major, minor, patchlevel)                       \
		(BOOST_GCC >= (major) * 10000 + (minor) * 100 + (patchlevel))

	#ifdef __posix
		#undef  __CORAX_POSIX
		#define __CORAX_POSIX 1
	#endif

	#ifdef __unix
		#undef  __CORAX_UNIX
		#define __CORAX_UNIX 1
	#endif

	#ifdef __linux
		#undef  __CORAX_LINUX
		#define __CORAX_LINUX 1
	#endif

#else
	#warning "Not implemented for compilers other than GCC"

#endif //__CORAX_GNUG
