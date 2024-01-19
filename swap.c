#include "monty.h"

/**
 * swap - Swap the top two elements on the stack
 * @stack: Double pointer to the head of the stack (unused)
 * @line_number: Line number in the source file
 * Return: No explicit return value. Exits the program with EXIT_FAILURE
 *           upon error.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void) stack;

	if (global_args->stack_len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		close_stream();
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}
	temp1 = global_args->stack_head;
	temp2 = temp1->next;
	temp1->next = temp2->next;
	if (temp1->next)
		temp1->next->prev = temp1;
	temp2->next = temp1;
	temp1->prev = temp2;
	temp2->prev = NULL;
	global_args->stack_head = temp2;
}


