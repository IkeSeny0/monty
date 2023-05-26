#include "monty.h"

/**
 * f_pall - Prints all elements of the stack.
 * @head: Stack head.
 * @counter: Line number (not used).
 * Return: No return value.
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void) counter;

	current = *head;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

