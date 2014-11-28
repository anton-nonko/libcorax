/**
\addtogroup error \{
\defgroup backtrace
\{
*/

#pragma once

#include <boost/preprocessor.hpp>
#include "config.h"

#if CORAX_BACKTRACE

///\cond
	#define __CORAX_BACKTRACE_BACKEND_EXECINFO 0
	#define                           execinfo 1
	#if CORAX_BACKTRACE_BACKEND == execinfo
		#undef  __CORAX_BACKTRACE_BACKEND_EXECINFO
		#define __CORAX_BACKTRACE_BACKEND_EXECINFO 1
		#define __CORAX_BACKTRACE_BACKEND_HEADER   <execinfo.h>

	#else
		#error "Only 'execinfo' may be used as CORAX_BACKTRACE_BACKEND value"

	#endif
	#undef execinfo
///\endcond

#include __CORAX_BACKTRACE_BACKEND_HEADER
#include "array.h++"

namespace corax {

struct backtrace {
	typedef typename array<void*, CORAX_BACKTRACE_SIZE>::const_iterator iterator;

	inline backtrace() noexcept :
		m_size{::backtrace(m_data.data(), m_data.size())}
	{};

	inline backtrace(const backtrace& other) noexcept = default;

	inline iterator begin() const noexcept {return m_data.data();         };
	inline iterator end()   const noexcept {return m_data.data() + m_size;};

private:
	std::array<void*, CORAX_BACKTRACE_SIZE> m_data;
	int                                     m_size;
}; //backtrace

}; //corax

#endif //CORAX_BACKTRACE

///\{ //backtrace
///\{ //error
