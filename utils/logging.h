#ifndef __LOGGING_H__
#define __LOGGING_H__

#ifdef DEBUG
#define debug(fmt, ...) fprintf(stdout, fmt, ##__VA_ARGS__)
#else
#define debug(fmt, ...) ((void)0)
#endif

#endif //__LOGGING_H__
