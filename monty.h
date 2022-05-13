#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <unistd.h>
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
	char *buf;
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


/* Main Functions */
void (*get_op_func(line_t line, global_t *global))(stack_t **, unsigned int);
void readline(char *buf, line_t *line);
void readfile(FILE *fp);

/* Checker Functions */
void checker(line_t line, global_t *global, char *opcode);
int check_argument(char *str);

/* Op Functions */
stack_t *create_node(int n);
void push(stack_t **stack, unsigned int number_line);
void pall(stack_t **stack, unsigned int number_line);
void pint(stack_t **stack, unsigned int number_line);
void swap(stack_t **stack, unsigned int number_line);
void add(stack_t **stack, unsigned int number_line);
void nop(stack_t **stack, unsigned int number_line);
void pop(stack_t **stack, unsigned int number_line);
void sub(stack_t **stack, unsigned int number_line);
void mul(stack_t **stack, unsigned int number_line);

/* Aux functions */
void free_stack(stack_t **stack);
void free_elements_in_structs(line_t line, global_t *global);

#endif /*MONTY_H*/
