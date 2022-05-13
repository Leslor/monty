#include "monty.h"

/**
 * free_stack - Free stack_t list
 * @stack: The pointer to the head of the stack_t list
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = NULL;

	if (stack == NULL || *stack == NULL)
		return;

	tmp = *stack;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * free_elements_in_structs - Free elements of line_t and global_t structs
 * @line: line_t Struct
 * @global: global_t Struct
 *
 * Return: void
 */
void free_elements_in_structs(line_t line, global_t *global)
{
	free(line.tokens);
	free_stack(&(global->stack));
	fclose(global->file);
	free(global->buf);
	free(global);
}
