#include "monty.h"
/**
 * free_node - function that frees all node
 * and sets the head to NULL
 * @head: pointer to the head node
 */
void free_node(stack_t **head)
{
	stack_t *current;
	stack_t *tmp;

	current = *head;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*head = NULL;
}
