#include <sstream>
#include "os_conf.h"

#define    SIGTRAP        5    /* Trace/breakpoint trap.  */
#define    SIGKILL        9    /* Killed.  */

#if defined(BLOCKCHAIN_DEBUG)
# 	if defined(UNIX_SIGNALS_AVAILABLE) || defined(__CYGWIN__)
	#	define BLOCKCHAIN_ASSERT(exp) { 												\
		if (!(exp)) 																	\
		{ 																				\
			std::ostringstream oss; 													\
			oss << "Assertion failed: " << __FILE__ << "(" 								\
				<< __LINE__ << "): " 													\
				<< __func__ << std::endl; 												\
			std::cout << std::flush; 													\
			std::cerr << oss.str(); 													\
			raise(SIGTRAP); 															\
		} 																				\
	}																					
#endif // Unix
#endif // Debug Enabled