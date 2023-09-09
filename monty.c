#include "monty.h"
/**
 * read_file_content - function that reads a file from the stdin
 * @filename: pointer to the input file
 */
void read_file_content(char *filename)
{
	FILE *fd;
	char *buffer = NULL;
	ssize_t nread;
	size_t len = 0;
	int line_number = 1;

	if (filename == NULL)
	{
		print_error(1);
		exit(EXIT_FAILURE);
	}
	fd = fopen(filename, "r");
	if (fd == NULL)
	{
		print_error(2, filename);
		exit(EXIT_FAILURE);
	}

	for (line_number = 1; (nread = getline(&buffer, &len, fd)) != -1;
	line_number++)
	{
		execute_buffer(buffer, line_number);

	}

	if (line_number == 0)
	{
		print_error(1);
		exit(EXIT_FAILURE);
	}
	fclose(fd);
	free(buffer);

}



/**
 * execute_buffer - function that execute buffer
 * @buffer: buffer to execute
 * @line_number: keeps track of the line being proccessed
 * Return: return 1 if stack operation or 0 if otherwise
 */
int execute_buffer(char *buffer, int line_number)
{
	int is_stack = 0;
	char *arg, *opcode;

	opcode = strtok(buffer, "\n ");

	if (opcode == NULL)
	{
		return (is_stack);
	}
	arg = strtok(NULL, "\n ");

	if (strcmp(opcode, "stack") == 0)
	{
		is_stack = 1;
		return (is_stack);
	}
	if (strcmp(opcode, "queue") == 0)
	{
		is_stack = 0;
		return (is_stack);
	}
	get_func(opcode, line_number, arg, is_stack);

	return (is_stack);
}


/**
 * get_func - function that return appropriate opcode function
 * @opcode: pointer to the opcode
 * @ln: line number where operation is being done
 * @arg: argument to be passed to push
 * @is_stack: dicide which operation, either stack or queue
 */
void get_func(char *opcode, unsigned int ln, char *arg, int is_stack)
{
	int i, flag = 1;

	instruction_t opcodes_func[] = {
	{"push", push_to_stack},
	{"pall", print_stack_element},
	{"pint", print_top_element},
	{"pop", pop_top},
	{NULL, NULL}
	};

	if (opcode[0] == '#')
	{
		return;
	}

	for (i = 0; opcodes_func[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes_func[i].opcode, opcode) == 0)
		{
			_func(opcodes_func[i].f, opcode, arg, ln, is_stack);
			flag = 0;
		}
	}

	if (flag == 1)
	{
		print_error(3, ln, opcode);
	}
}
