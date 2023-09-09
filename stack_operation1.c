#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>
/**
 * create_new_node - function that creates a new_node
 * @n: data element in the new_node
 * Return: retunr the address of the new node created
 */
stack_t *head = NULL;
stack_t *create_new_node(int n)
{
	stack_t *new_node;

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		print_error(4);
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}


/**
 * push_to_stack - function that push new node created to the stack
 * @new_node: now node to be pushed
 * @line_number: line_number being processed
 */
void push_to_stack(stack_t **new_node, __attribute__((unused))
unsigned int line_number)
{
	stack_t *temp;

	if (*new_node == NULL)
	{
		print_error(5, line_number);
		exit(EXIT_FAILURE);
	}

	if (head != NULL)
	{
		temp = head;
		head = *new_node;
		head->next = temp;
		temp->prev = head;
	}
	else
	{
		head = *new_node;
	}
}


/**
 * print_stack_element - function that print element of the stack
 * @head: pointes to the head node
 * @line_number: unused line number
 *
 */
void print_stack_element(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}



/**
 * push_to_queue - function that adds a new node to the queue
 * @new_node: the new node to be added
 * @line_number: the opcode line being processed
 *
 */
void push_to_queue(stack_t **new_node, __attribute__((unused))
unsigned int line_number)
{
	stack_t *current;

	if (new_node == NULL)
	{
		print_error(5, line_number);
		exit(EXIT_FAILURE);
	}
	(*new_node)->next = NULL;

	if (head == NULL)
	{
		(*new_node)->prev = NULL;
		head = *new_node;
	}
	else
	{
		current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = *new_node;
		(*new_node)->prev = current;
	}
}
