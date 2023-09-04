#include "monty.h"
/**
 * read_file_content - function that reads a file from the stdin
 * @filename: pointer to the input file
 * Return: return buffer of the file read
 */
char *read_file_content(char *filename)
{
	FILE *fd;
	char *buffer = NULL;
	ssize_t nread, size = 0;
	size_t len = 0;
	
	if (filename == NULL)
	{
		print_error(1);
		exit(EXIT_FAILURE);
	}
	fd = fopen(filename, "r");

	while ((nread = getline(&buffer, &len, fd)) != -1)
	{
		size += nread;
	}

	if (size == 0)
	{
		print_error(1);
		exit(EXIT_FAILURE);
	}
	fclose(fd);

	return (buffer);
}



/**
 * execute_buffer - function that execute buffer
 * @buffer: buffer to execute
 */
void execute_buffer(char *buffer)
{
	unsigned int line_number = 1;
	int is_stack = 1;
	char *arg, *opcode;

	if (buffer == NULL)
	{
		print_error(2);
		exit(EXIT_FAILURE);
	}
	opcode = strtok(buffer, " \t\n\r");

	while (opcode != NULL)
	{
		arg = strtok(NULL, " \t\n\r");
		printf("opcodes is (%s) and argument are %s\n", opcode, arg);
		is_stack = get_stack_or_queue(opcode, line_number, arg, is_stack);
		line_number++;
	}
	free(buffer);
}

/**
 * get_stack_or_queue - function that checks if operation is to be done on
 * either stack or queue
 * @line_number: the line at which code is processed
 * @arg: argument in the opcode
 * @is_stack: detemine
 * @opcode: operation codes
 * Return: return 1 for stack operation and 0 for queue operation
 */
int get_stack_or_queue(char *opcode, unsigned int line_number,
char *arg, int is_stack)
{

	if (strcmp(opcode, "stack") == 0)
	{
		return (1);
	}
	else if (strcmp(opcode, "queue") == 0)
	{
		return (0);
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
	int i, flag = 0;

	instruction_t opcodes_func[] = {
	{"push", push_to_stack},
	{"pall", print_stack_element},
	{NULL, NULL}
	};

	if (opcode[0] == '#')
	{
		return;
	}

	while (opcode)
	{
		flag = 1;

		for (i = 0; opcodes_func[i].opcode != NULL; i++)
		{
			if (strcmp(opcodes_func[i].opcode, opcode) == 0)
			{
				_func(opcodes_func[i].f, opcode, arg, ln, is_stack);
				flag = 0;
			}
		}
		opcode = strtok(NULL, "\n");
	}
	if (flag == 1)
	{
		print_error(3, ln, opcode);
		exit(EXIT_FAILURE);
	}
}
