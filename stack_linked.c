#include <stdio.h>
#include <stdlib.h>
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;


stack_t *top = NULL;

void push(int n)
{
  stack_t *newNode = NULL;
  newNode = malloc(sizeof(newNode));
  if (newNode == NULL)
  {
    fprintf(stderr, "[ERROR]"
     ": malloc failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->n = n;  
  newNode->next = top;
  newNode->prev = NULL;
  top = newNode;
}

void pall()
{
	stack_t *temp = top;

	while(temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

void pint()
{	
  if (top == NULL)
  {
    fprintf(stderr, "L%u: can't pint, stack\n", __LINE__);
    exit(EXIT_FAILURE);
  }
  printf("%d\n", top->n);
}

void pop()
{
	stack_t *temp1 = top;

	if (temp1 == NULL)
	{
		//cambiar el Line por el numero de linea correcto
		fprintf(stderr, "L%u: can't pop an empty stack\n", __LINE__);	
		exit(EXIT_FAILURE);
	}
	top = top->next;
	top->prev = NULL;
	temp1->next = NULL;
	//free(temp1);
}
void swap()
{
	stack_t *temp3;

	if (top == NULL || top->next == NULL)
	{
		//cambiar el Line por el numero de linea correcto
		fprintf(stderr, "L%u: can't swap too short\n", __LINE__);	
		exit(EXIT_FAILURE);
	}
	temp3 = top->next;
	top->prev = temp3;
	top->next = temp3->next;
	temp3->prev = NULL;

	if (temp3->next)
			temp3->next->prev = top;
	temp3->next = top;
	top = temp3;
}
void add()
{
	int result;
	stack_t *temp4;

	if (top == NULL || top->next == NULL)
	{
		//cambiar el Line por el numero de linea correcto
		fprintf(stderr, "L%u: can't add, stack too short\n", __LINE__);	
		exit(EXIT_FAILURE);
	}
	temp4 = top->next;
	result = top->n + temp4->n;

}


int main() {

	int data1 = 1, data2 = 2, data3 = 3;
	push(data1);
	push(data2);
	push(data3);
	pall();
	swap();
	pall();
	return (0);
}
