#include "monty.h"
/**
 * pint - Print the top value on the stack
 * @stack: Double pointer to the head of the stack (unused)
 * @line_number: Line number in the source file
 * Return: No explicit return value. Exits the program with EXIT_FAILURE
 *           upon error.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;

	if (!global_args->stack_head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		close_stream();
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", global_args->stack_head->n);
}
