#include "monty.h"


arguments_t *global_args = NULL;

/**
 * main - Entry point of the program
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: 0 on success, otherwise non-zero
 */

int main(int argc, char **argv)
{
	size_t n = 0;
	(void) argv;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global_args = malloc(sizeof(arguments_t));
	if (!global_args)
		malloc_failed();
	global_args->instr_ptr = malloc(sizeof(instruction_t));
	if (!global_args->instr_ptr)
		malloc_failed();
	global_args->f_content = NULL;
	global_args->line = NULL;
	global_args->num_tokens = 0;
	global_args->line_number = 0;
	global_args->stack_head = NULL;
	global_args->stack_len = 0;
	get_content(argv[1]);
	while (getline(&global_args->line, &n, global_args->f_content) != -1)
	{
		global_args->line_number += 1;
		get_tokens();
		get_instruction();
		execute_instruction();
		free_tokens();
	}
	close_stream();
	free_arguments();
	return (0);
}

/**
 * malloc_failed - Handles failure in malloc and exits the program
 * Return: Nothing
 */
void malloc_failed(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_arguments();
	exit(EXIT_FAILURE);
}

/**
 * close_stream - Closes the file stream
 * Return: Nothing
 */

void close_stream(void)
{
	if (!global_args->f_content)
		return;
	fclose(global_args->f_content);
	global_args->f_content = NULL;
}

