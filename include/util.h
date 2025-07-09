#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <assert.h>

#define MIN_DA_INIT_CAP 256

#define min_da_append(da, item)												\
	do {																\
		if ((da)->count >= (da)->cap) {									\
			(da)->cap = (da)->cap == 0 ? MIN_DA_INIT_CAP : 2*(da)->cap;	\
			(da)->items = realloc((da)->items, (da)->cap*sizeof(*(da)->items)); \
			assert((da)->items != NULL && "Not enough memory");			\
		}																\
		(da)->items[(da)->count++] = item;								\
	} while(0)															\


#endif // UTIL_H
