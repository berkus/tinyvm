#ifndef VIRTUAL_MACHINE_H_
#define VIRTUAL_MACHINE_H_

#include "memory.h"
#include "program.h"
#include "stack.h"

/* "virtual_machine" is an object which holds the state of our vm. 
Creating a virtual_machine object creates all the other components 
we need at the same time. (Storage space for the code, the stack, and 
memory, among other things.) Destroying the virtual machine frees all
related objects as well. */

typedef struct
{
	program* pProgram;

	stack* pStack;

	memory* pMemory;

} virtual_machine;

virtual_machine* create_vm(char* filename);
void destroy_vm(virtual_machine* vm);

/* After creating a virtual_machine object, and interpreting a valid 
program, run_vm will execute the code stored in vm->pProgram. */
void run_vm(virtual_machine* vm);

#endif
