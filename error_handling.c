#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "monty.h"
/**
 * print_error - print error message based on number passed
 * ...: other argument to be passed
 * @error: error number to be passed
 */
void print_error(int error, ...)
{
	va_list user;
	int ln_num;
	char *file, *opcode;

	va_start(user, error);

	while (error)
	{
		if (error == 1)
		{
			fprintf(stderr, "USAGE: monty file\n");
			break;
		}
		else if (error == 2)
		{
			file = va_arg(user, char *);
			fprintf(stderr, "Cant'open file %s\n", file);
			break;
		}
		else if (error == 3)
		{
			ln_num = va_arg(user, int);
			opcode = va_arg(user, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", ln_num, opcode);
			break;
		}
		else if (error == 4)
		{
			fprintf(stderr, "Error: malloc failed\n");
			break;
		}
		va_end(user);
	}
}
