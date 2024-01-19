#include "monty.h"
/**
 * pall - Print all values on the stack
 * @stack: Double pointer to the head of the stack (unused)
 * @line_number: Line number in the source file (unused)
 * Return: No explicit return value. Exits the program with EXIT_FAILURE
 *           upon error.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	(void) stack;

	if (!global_args->stack_head)
		return;
	temp = global_args->stack_head;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
