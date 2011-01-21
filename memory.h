#ifndef VIRTUALMEMORY_H_
#define VIRTUALMEMORY_H_

#include <stdlib.h>

typedef struct
{
	/* These integers serve as boolean values, equivalent to certain bits
	set in the FLAGS register of an x86 machine */
	int equal;
	int greater;

	int remainder;

	// System memory
	int* int32;

} memory;

memory* create_memory(size_t size);
void destroy_memory(memory* mem);

#endif
