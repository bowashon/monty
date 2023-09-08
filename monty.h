#ifndef HEADER_FILE
#define HEADER_FILE
#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *new_node;
extern stack_t *head;

char *strtrim(char *str);
void print_error(int error, ...);
typedef void (*fun)(stack_t **stack, unsigned int line_number);

/********file operation******/
void read_file_content(char *filename);
void execute_buffer(char *buffer, int line_number);
int get_stack_or_queue(char *opcode, unsigned int line_number,
char *arg, int is_stack);
void get_func(char *opcode, unsigned int ln, char *arg, int is_stack);

/*****stack operations*******/
void push_to_stack(stack_t **new_node, __attribute__((unused)) unsigned int);
stack_t *create_new_node(int n);
void _func(fun func, char *opcode, char *arg, int lin_num, int is_stack);
void print_stack_element(stack_t **head, unsigned int line_number);
void push_to_queue(stack_t **new_node, __attribute__((unused))
unsigned int line_number);

#endif /**** monty header *****/

