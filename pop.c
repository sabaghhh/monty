#include "monty.h"
/**
 * pop - Remove the top element from the stack
 * @stack: Double pointer to the head of the stack (unused)
 * @line_number: Line number in the source file
 * Return: No explicit return value. Exits the program with EXIT_FAILURE
 *           upon error.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) stack;

	if (!global_args->stack_head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		close_stream();
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}
	temp = global_args->stack_head;
	global_args->stack_head = temp->next;
	free(temp);
	global_args->stack_len -= 1;
}
