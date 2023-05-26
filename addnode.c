#include "monty.h"

/**
 * addNode - Adds a new node to the head of the stack.
 * @head: Pointer to the head of the stack.
 * @value: New value for the node.
 * Return: No return value.
 */
void addNode(stack_t **head, int value)
{
	stack_t *newNode, *current;

	current = *head;
	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (current)
		current->prev = newNode;

	newNode->n = value;
	newNode->next = *head;
	newNode->prev = NULL;
	*head = newNode;
}

