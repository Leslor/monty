#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct line_s - Struct for manipulate each line in a file
 * @number: Line number
 * @tokens: Tokens of the line
 *
 * Description: Line in a file
 */
typedef struct line_s
{
	unsigned int number;
	char **tokens;
} line_t;

/**
 * struct global_s - file and stack
 * @file: File descriptor
 * @stack: stack_t list
 *
 * Description: file and stack
 */
typedef struct global_s
{
	FILE *file;
	stack_t *stack;
} global_t;

/**
 * struct arg_s - Argument values
 * @n: Integer number
 *
 * Description: Argument values
 */
typedef struct arg_s
{
	int n;
} arg_t;

extern arg_t argument;


/*Protoripe Functions */
void (*get_op_func(line_t line, global_t *global))(stack_t **, unsigned int);
void free_stack(stack_t **stack);

/* Checker Functions */
void check_push(line_t line, global_t *global, char *opcode);
#endif /*MONTY_H*/
