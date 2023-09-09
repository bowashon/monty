#include "monty.h"
/**
 * print_top_element - function that prints the top element
 * of a stack_t doubly linked list.
 * @head: points to the head node,
 * @line_number: unused parameter
 */
void print_top_element(stack_t **head, unsigned int line_number)
{
	(void)line_number;

	if (*head == NULL || head == NULL)
	{
		string_error(6);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}


/**
 * pop_top - function that removes the top element of the stack
 * @head: points to the head node
 * @line_number: unsused parameter
 *
 */
void pop_top(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (*head == NULL)
	{
		string_error(7);
		exit(EXIT_FAILURE);
	}
	current = *head;
	*head = (*head)->next;
	free(current);
	
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
}

