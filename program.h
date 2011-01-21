#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "instruction_index.h"
#include "hash_table.h"
#include "memory.h"

/* "program" is an object used to store TVM bytecode prior to and during execution. 
The function "create_program" takes a filename as an argument, translates the program
into TVM bytecode, then stores it in a "program" object. It then returns a pointer to the newly
created program. */

typedef struct
{
	// Where to begin executing the program
	int start;

	// The number of instructions in the program
        unsigned int num_instructions;

	// An array that stores TVM opcodes as integers
        int* instr;

	// An array of arguments to TVM instructions
        int*** args;

	// A hash tabel used for storing and looking up labels, and their corresponding addresses
	hash_table* label_htab;

	// A dynamically allocated array used to store static values from a program
	int** values;
	int num_values;

} program;

program* create_program(char* filename, memory* pMemory);
void destroy_program(program* p);

// Add a static value to the values array of a program object, returning a pointer to the resulting value
int* add_value(program* p, const int val);

// Parse a value stored as a text string, converting from the base specified
int parse_value(char* str);

void print_warning(char* str, int line_number);
void print_error(char* str, int line_number);

#endif
