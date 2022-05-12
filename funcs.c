#include "monty.h"

/**
 * push - add a new node to the stack
 * @stack:  the top of the stack
 * @number_line: number of the monty file to execute
 * Return: void
 */

void push(stack_t **stack, unsigned int number_line)
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
	stack_t *temp1 = *stack;

	if (temp1 == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", number_line);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	temp1->next = NULL;
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

	if (stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap too short\n", number_line);
		exit(EXIT_FAILURE);
	}
	temp3 = (*stack)->next;
	(*stack)->prev = temp3;
	(*stack)->next = temp3->next;
	temp3->prev = NULL;

	if (temp3->next)
		temp3->next->prev = (*stack);
	temp3->next = (*stack);
	(*stack) = temp3;
}

/**
 * nop - Do nothing
 * @stack:  the top of the stack
 * @number_line: number of the monty file to execute
 * Return: void
 */
void nop(stack_t **stack, unsigned int number_line)
{
}

/**
 * add - add 2 tops elements of the stack
 * @stack:  the top of the stack
 * @number_line: number of the monty file to execute
 * Return: void
 */

void add(stack_t **stack, unsigned int number_line)
{
	int result;
	stack_t *temp4;

	if (stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", number_line);
		exit(EXIT_FAILURE);
	}
	temp4 = (*stack)->next;
	result = (*stack)->n + temp4->n;
	temp4->next->n = result;

	(*stack) = temp4->next;
}
