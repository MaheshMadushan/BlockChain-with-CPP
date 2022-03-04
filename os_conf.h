#if (defined(DEBUG) || defined(__DEBUG__)) || (defined(NDK_DEBUG) && (NDK_DEBUG > 0))
# undef BLOCKCHAIN_DEBUG
# define BLOCKCHAIN_DEBUG 1
#endif




// Unix and Linux platforms
#if defined(__unix__) || defined(__MACH__) || defined(__NetBSD__) || defined(__sun)
#define BLOCKCHAIN_UNIX_AVAILABLE
#endif

// Handle processes using signals
// eg : pause a process
// Cygwin/Newlib requires _XOPEN_SOURCE=600
#if defined(BLOCKCHAIN_UNIX_AVAILABLE)
# define UNIX_SIGNALS_AVAILABLE 1
#endif