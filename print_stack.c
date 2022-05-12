#include "monty.h"

/**
 * create_node - Creat the node
 * @n: The n for create the node
 *
 * Return: void
 */
stack_t *create_node(int n)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;
	newNode->prev = NULL;

	return (newNode);
}


/**
 * pall - print all th stack
 * @stack: The pointer to the head of the stack_t list
 * @number_line: number line of the file
 * Return: void
 */

void pall(stack_t **stack, __attribute__((unused)) unsigned int number_line)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - print the top
 * @stack: The pointer to the head of the stack_t list
 * @number_line: number line of the file
 * Return: void
 */
void pint(stack_t **stack, __attribute__((unused)) unsigned int number_line)
{
	printf("%d\n", (*stack)->n);
}
