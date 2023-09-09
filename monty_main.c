#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - check the code
 * @argc: command line arguments passed
 * @argv: pointer array to the command line arguments
 * Return: return exit success
 */
int main(int argc, char *argv[])
{
	char *filename;

	if (argc != 2)
	{
		print_error(1);
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	read_file_content(filename);


	exit(EXIT_SUCCESS);
}
