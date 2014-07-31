#ifndef DEBUG_H_
#define DEBUG_H_

#define DEBUG 1
/* define DEBUG 0 to deactivate debug messages! */
#if DEBUG==1
# define DEBUG_PRINT(x) printf x
#else
# define DEBUG_PRINT(x) do {} while (0)
#endif

#endif /* DEBUG_H_ */
