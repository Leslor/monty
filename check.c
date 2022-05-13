#include "monty.h"

arg_t argument = {0};

/**
 * check_argument - check the argument of the push function
 * @str: ...
 * Return: int 0 or 1
 */
int check_argument(char *str)
{
	unsigned int i = 0;

	if (!str)
		return (0);
	if (*str == '-')
	{
		str++;
		if (*str < '0' || *str > '9')
			return (0);
	}
	for (i = 0; *(str + i); i++)
	{
		if (*(str + i) < '0' || *(str + i) > '9')
			return (0);
	}
	return (1);
}

/**
 * checker - check the validation if is necesary
 * @line: line_t Struct
 * @global: global_t Struct
 * @opcode: Command put by the user
 * Return: void
 */
void checker(line_t line, global_t *global, char *opcode)
{
	if (strcmp(opcode, "push") == 0 && !check_argument(line.tokens[1]))
	{
		free_elements_in_structs(line, global);
		fprintf(stderr, "L%d: usage: push integer\n", line.number);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
		argument.n = atoi(line.tokens[1]);
}
