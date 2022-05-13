#include "monty.h"

/**
 * sub - sub 2 tops elements of the stack
 * @stack:  the top of the stack
 * @number_line: number of the monty file to execute
 * Return: void
 */

void sub(stack_t **stack, unsigned int number_line)
{
	long result;
	stack_t *temp4;

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", number_line);
		exit(EXIT_FAILURE);
	}
	temp4 = *stack;
	(*stack) = (*stack)->next;
	result = (*stack)->n - temp4->n;
	(*stack)->n = result;

	free(temp4);
}


/**
 * mul - mul 2 tops elements of the stack
 * @stack:  the top of the stack
 * @number_line: number of the monty file to execute
 * Return: void
 */

void mul(stack_t **stack, unsigned int number_line)
{
	long result;
	stack_t *temp4;

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", number_line);
		exit(EXIT_FAILURE);
	}
	temp4 = *stack;
	(*stack) = (*stack)->next;
	result = (*stack)->n * temp4->n;
	(*stack)->n = result;

	free(temp4);
}
