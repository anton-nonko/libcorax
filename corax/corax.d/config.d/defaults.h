#pragma once

#include "lang.h"
#include "system.h"

#define __CORAX_DEFAULT_DEBUG 0

#define __CORAX_DEFAULT_LOG   0

#if __CORAX_POSIX || __CORAX_UNIX || __CORAX_LINUX
	#define __CORAX_DEFAULT_LOG_BACKEND syslog
#else
	#define __CORAX_DEFAULT_LOG_BACKEND none
#endif

#define __CORAX_DEFAULT_BACKTRACE      1
#define __CORAX_DEFAULT_BACKTRACE_SIZE 256

#if __CORAX_POSIX || __CORAX_UNIX || __CORAX_LINUX
	#define __CORAX_DEFAULT_BACKTRACE_BACKEND execinfo
#else
	#define __CORAX_DEFAULT_BACKTRACE_BACKEND none
#endif

#if __CORAX_CXX14_ANY
	#define __CORAX_DEFAULT_ANY_BACKEND std
#else
	#define __CORAX_DEFAULT_ANY_BACKEND boost
#endif

#if __CORAX_CXX14_OPTIONAL
	#define __CORAX_DEFAULT_OPTIONAL_BACKEND std
#else
	#define __CORAX_DEFAULT_OPTIONAL_BACKEND boost
#endif

#if __CORAX_CXX11_THREAD
	#define __CORAX_DEFAULT_THREAD_BACKEND std
#else
	#define __CORAX_DEFAULT_THREAD_BACKEND boost
#endif
