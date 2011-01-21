#ifndef STACK_H_
#define STACK_H_

/* This object is a last in, first out (LIFO) data structure known as a stack.
It consists of an array of objects (32-bit integers, in this case) which are manipulated
using push and pop instructions. Push adds an item to the top of the stack, and pop removes
an item from the top of the stack. Operations are always done on the top of the stack.
No members of the stack below the top are accessible before removing the items above it.*/

typedef struct
{
	int* items;
	int num_items;
} stack;

stack* create_stack();
void destroy_stack(stack* s);

inline void stack_push(stack* s, int* item);
inline void stack_pop(stack* s, int* dest);

#endif
