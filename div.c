#include "monty.h"

/**
 * f_div - Divides the top two elements of the stack.
 * @head: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return value.
 */
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stack_size = 0, result;

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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	/* Division by zero check */
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	result = current->next->n / current->n; /* Perform division operation */
	current->next->n = result; /* Update the second element with the division result */
	*head = current->next;
	free(current); /* Free the old top element */
}

