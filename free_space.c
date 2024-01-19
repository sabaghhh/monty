#include "monty.h"

/**
 * free_tokens - Frees memory allocated for tokens
 * Return: Nothing
 */

void free_tokens(void)
{
	int i = 0;

	if (!global_args->token_arr)
		return;
	while (global_args->token_arr[i])
	{
		free(global_args->token_arr[i]);
		i++;
	}
	free(global_args->token_arr);
	global_args->token_arr = NULL;
}


/**
 * free_arguments - Frees memory allocated for global arguments
 * Return: Nothing
 */

void free_arguments(void)
{
	if (!global_args)
		return;
	if (global_args->instr_ptr)
	{
		free(global_args->instr_ptr);
		global_args->instr_ptr = NULL;
	}
	if (global_args->stack_head)
	{
		free_stack(global_args->stack_head);
		global_args->stack_head = NULL;
	}
	if (global_args->line)
	{
		free(global_args->line);
		global_args->line = NULL;
	}
	free(global_args);
	global_args = NULL;
}

/**
 * free_stack - Recursively frees the memory allocated for a stack
 * @head: Pointer to the head of the stack
 * Return: Nothing
 */

void free_stack(stack_t *head)
{
	if (!head)
		return;
	if (head->next)
		free_stack(head->next);
	free(head);
}
