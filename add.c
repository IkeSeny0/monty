#include "monty.h"

/**
 * f_add - Adds the top two elements of the stack.
 * @head: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return value.
 */
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stack_size = 0, sum;

	current = *head;

	/* Count the number of elements in the stack */
	while (current)
	{
		current = current->next;
		stack_size++;
	}

	/* If stack has less than 2 elements, display an error message and exit */
	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	sum = current->n + current->next->n;  /* Calculate the sum of the top two elements */
	current->next->n = sum;  /* Update the second element with the sum */
	*head = current->next;
	free(current);  /* Free the old top element */
}

