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
		{NULL, NULL}
	};

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, line.tokens[0]) == 0)
		{
			if (strcmp(ops[i].opcode, "push") == 0)
				check_push(line, global, ops[i].opcode);
			free(line.tokens);
			return (ops[i].f);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line.number,
		line.tokens[0]);
	free(line.tokens);
	free_stack(&(global->stack));
	fclose(global->file);
	free(global);
	exit(EXIT_FAILURE);
}
