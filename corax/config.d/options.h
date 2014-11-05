#pragma once

#include "defaults.h"

#ifndef CORAX_DEBUG
	/*!
	 * Enable/disable debugging support.
	 */
	#define CORAX_DEBUG __CORAX_DEFAULT_DEBUG
#endif

#ifndef CORAX_LOG
	/*!
	 * Enable/disable \c std::log redirection support.
	 */
	#define CORAX_LOG __CORAX_DEFAULT_LOG
#endif

#ifndef CORAX_LOG_BACKEND
	/*!
	 * Backend to use for logging. Available backends are:
	 * \li \c syslog
	 *
	 * \sa CORAX_LOG
	 */
	#define CORAX_LOG_BACKEND __CORAX_DEFAULT_LOG_BACKEND
#endif

#ifndef CORAX_BACKTRACE
	/*!
	 * Enable/disable function call backtrace support for exceptions.
	 */
	#define CORAX_BACKTRACE __CORAX_DEFAULT_BACKTRACE
#endif

#ifndef CORAX_BACKTRACE_SIZE
	/*!
	 * Maximum number of backtrace frames.
	 * \sa CORAX_BACKTRACE
	 */
	#define CORAX_BACKTRACE_SIZE __CORAX_DEFAULT_BACKTRACE_SIZE
#endif

#ifndef CORAX_BACKTRACE_BACKEND
	/*!
	 * Backend to use for backtrace retrieval. Available backends are:
	 * \li \c execinfo
	 *
	 * \sa CORAX_BACKTRACE
	 */
	#define CORAX_BACKTRACE_BACKEND __CORAX_DEFAULT_BACKTRACE_BACKEND
#endif

#ifndef CORAX_ANY_BACKEND
	/*!
	 * Backend to use as \c corax::any. Available backends are:
	 * \li \c std
	 * \li \c boost
	 */
	#define CORAX_ANY_BACKEND __CORAX_DEFAULT_ANY_BACKEND
#endif

#ifndef CORAX_OPTIONAL_BACKEND
	/*!
	 * Backend to use as \c corax::optional. Available backends are:
	 * \li \c std
	 * \li \c boost
	 */
	#define CORAX_OPTIONAL_BACKEND __CORAX_DEFAULT_OPTIONAL_BACKEND
#endif

#ifndef CORAX_THREAD_BACKEND
	/*!
	 * Backend to use for multithreading support. Available backends are:
	 * \li \c std
	 * \li \c boost
	 */
	#define CORAX_THREAD_BACKEND __CORAX_DEFAULT_THREAD_BACKEND
#endif
