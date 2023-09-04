#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * main - check the code
 * @argc: command line arguments passed
 * @argv: pointer array to the command line arguments
 * Return: return exit success
 */
stack_t *head = NULL;

int main(int argc, char *argv[])
{
	char *filename;
	char *buffer;
	
	if ( argc != 2)
	{
		print_error(1);
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	buffer = read_file_content(filename);
	if (buffer == NULL)
	{
		print_error(2, filename);
		exit(EXIT_FAILURE);
	}

	execute_buffer(buffer);

	free(buffer);

	exit(EXIT_SUCCESS);
}
