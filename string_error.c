#include "monty.h"
/**
 * _string_error - prints error to the stdout
 * @error_num: number to call error
 */
void _string_error(int error_num, ...)
{
	va_list user;
	int line_number;

	va_start(user, error_num);

	line_number = va_arg(user, int);
	while (error_num)
	{
		if (error_num == 5)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			break;
		}

		else if (error_num == 6)
		{
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
			break;
		}
		else if (error_num == 7)
		{
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
			break;
		}
		else if (error_num == 8)
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
			break;
		}
		else if (error_num == 9)
		{
			fprintf(stderr, ":%d: can't add, stack too short\n", line_number);
			break;
		}
	}
	va_end(user);
}



/**
 *_func - function that calls the appropriate function for operation
 * @func: opcodes function pointer
 * @opcode: opcode
 * @arg: arguments
 * @lin_num: line number
 * @is_stack: decide if operation is on stack or on queue
 */
void _func(fun func, char *opcode, char *arg, int lin_num, int is_stack)
{
	int sign = 1;
	int i = 0;
	stack_t *node;

	if (strcmp(opcode, "push") == 0)
	{
		if (arg != NULL && arg[0] == '-')
		{
			arg = arg + 1;
			sign = -1;
		}
		if (arg == NULL)
		{
			_string_error(5, lin_num);
			exit(EXIT_FAILURE);
		}
		while (arg[i] != '\0')
		{
			if (!(isdigit(arg[i])))
			{
				_string_error(5, lin_num);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		node = create_new_node(atoi(arg) * sign);
		if (is_stack == 1)
			push_to_stack(&node, lin_num);
		else if (!is_stack)
			push_to_queue(&node, lin_num);
	}
	else
		func(&head, lin_num);
}
