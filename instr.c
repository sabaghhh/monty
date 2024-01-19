#include "monty.h"

/**
 * get_content - Reads the content of a file and opens it for reading
 * @fileName: Name of the file to be read
 * Return: Nothing
 */

void get_content(char *fileName)
{
	int fd;

	fd = open(fileName, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		free_arguments();
		exit(EXIT_FAILURE);
	}

	global_args->f_content = fdopen(fd, "r");
	if (!global_args->f_content)
	{
		close(fd);
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		free_arguments();
		exit(EXIT_FAILURE);
	}
}


/**
 * get_tokens - Tokenizes the input line and stores tokens in an array
 * Return: Nothing
 */

void get_tokens(void)
{
	int i = 0;
	char *delims = " \n", *token = NULL, *linecpy = NULL;


	linecpy = malloc(sizeof(char) * (strlen(global_args->line) + 1));
	strcpy(linecpy, global_args->line);
	global_args->num_tokens = 0;
	token = strtok(linecpy, delims);
	while (token)
	{
		global_args->num_tokens += 1;
		token = strtok(NULL, delims);
	}
	global_args->token_arr = malloc(sizeof(char *) * (global_args
				->num_tokens + 1));
	strcpy(linecpy, global_args->line);
	token = strtok(linecpy, delims);
	while (token)
	{
		global_args->token_arr[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (!global_args->token_arr[i])
			malloc_failed();
		strcpy(global_args->token_arr[i], token);
		token = strtok(NULL, delims);
		i++;
	}
	global_args->token_arr[i] = NULL;
	free(linecpy);
}


/**
 * get_instruction - Matches the opcode with the corresponding function
 * Return: Nothing
 */

void get_instruction(void)
{
	int i = 0;

	instruction_t instructions[] = {
		{"push", &push}, {"pall", &pall},
		{"pint", &pint}, {"pop", &pop},
		{"swap", &swap}, {"add", &add},
		{"nop", &nop}, {"div", &my_div},
		{"mul", &mul}, {"sub", &sub},
		{"mod", &mod}, {NULL, NULL}
		};

	if (global_args->num_tokens == 0)
		return;
	for (; instructions[i].opcode; i++)
	{
		if (strcmp(instructions[i].opcode, global_args->token_arr[0]) == 0)
		{
			global_args->instr_ptr->opcode = instructions[i].opcode;
			global_args->instr_ptr->f = instructions[i].f;
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", global_args
			->line_number, global_args->token_arr[0]);
	close_stream();
	free_tokens();
	free_arguments();
	exit(EXIT_FAILURE);
}

/**
 * execute_instruction - Executes the instruction provided by the user
 * Return: Nothing
 */

void execute_instruction(void)
{
	stack_t *stack = NULL;

	if (global_args->num_tokens == 0)
		return;
	global_args->instr_ptr->f(&stack, global_args->line_number);
}

