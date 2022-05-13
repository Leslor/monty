#include "monty.h"

/**
 * push - add a new node to the stack
 * @stack:  the top of the stack
 * @number_line: number of the monty file to execute
 * Return: void
 */

void push(stack_t **stack, __attribute__((unused))unsigned int number_line)
{
	stack_t *newNode;

	newNode = create_node(argument.n);
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->next = *stack;
	if (*stack)
		(*stack)->prev = newNode;
	*stack = newNode;
}


/**
 * pop - delete a new node to the stack
 * @stack:  the top of the stack
 * @number_line: number of the monty file to execute
 * Return: void
 */

void pop(stack_t **stack, unsigned int number_line)
{
	stack_t *temp1;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", number_line);
		exit(EXIT_FAILURE);
	}

	temp1 = *stack;
	(*stack) = (*stack)->next;
	/*temp1->next = NULL;*/
	free(temp1);
}

/**
 * swap - swap the 2 tops of the stack
 * @stack:  the top of the stack
 * @number_line: number of the monty file to execute
 * Return: void
 */
void swap(stack_t **stack, unsigned int number_line)
{
	stack_t *temp3;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			number_line);
		exit(EXIT_FAILURE);
	}

	temp3 = (*stack);
	(*stack) = (*stack)->next;
	if ((*stack)->next)
	{
		temp3->next = (*stack)->next;
		(*stack)->next->prev = temp3;
	}
	else
	{
		temp3->next = NULL;
	}
	(*stack)->next = temp3;
	temp3->prev = (*stack);
	(*stack)->prev = NULL;
}

/**
 * nop - Do nothing
 * @stack:  the top of the stack
 * @number_line: number of the monty file to execute
 * Return: void
 */
void nop(stack_t **stack, unsigned int number_line)
{
	(void) stack;
	(void) number_line;
}

/**
 * add - add 2 tops elements of the stack
 * @stack:  the top of the stack
 * @number_line: number of the monty file to execute
 * Return: void
 */

void add(stack_t **stack, __attribute__((unused))unsigned int number_line)
{
	int result;
	stack_t *temp4;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			number_line);
		exit(EXIT_FAILURE);
	}

	temp4 = *stack;
	(*stack) = (*stack)->next;
	result = (*stack)->n + temp4->n;
	(*stack)->n = result;

	free(temp4);
}
