#include "monty.h"

/**
 * get_op_func - Match the tokens to each function.
 *
 * @line: Struct line_t.
 * @global: Struct global_t.
 *
 * Return: void
 */
void (*get_op_func(line_t line, global_t *global))(stack_t **, unsigned int)
{
	unsigned int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{NULL, NULL}
	};

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, line.tokens[0]) == 0)
		{
			checker(line, global, ops[i].opcode);
			free(line.tokens);
			return (ops[i].f);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction%s \n", line.number,
					line.tokens[0]);
	free(line.tokens);
	free_stack(&(global->stack));
	fclose(global->file);
	free(global->buf);
	free(global);
	exit(EXIT_FAILURE);
}

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
