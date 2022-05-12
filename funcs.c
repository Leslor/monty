#include "monty.h"

stack_t *create_node(int n)
{
	stack_t *newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;
	newNode->prev = NULL;

	return (newNode);
}

void push(stack_t **stack, unsigned int number_line)
{
	stack_t *newNode = create_node(argument.n);
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

void pall(stack_t **stack, unsigned int number_line)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
		return;

	while(temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

void pint(stack_t **stack, unsigned int number_line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", number_line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
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

int main(int ac, char **av)
{
	FILE *fp;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	readfile(fp);

	exit(EXIT_SUCCESS);
}
