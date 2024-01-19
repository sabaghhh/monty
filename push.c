#include "monty.h"
/**
 * push - Add an integer to the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the source file
 * Return: No explicit return value. Exits the program with EXIT_FAILURE
 *           upon error.
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (global_args->num_tokens <= 1 || !(is_num(global_args->token_arr[1])))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		close_stream();
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}
	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_failed();
	(*stack)->next = (*stack)->prev = NULL;
	(*stack)->n = (int) atoi(global_args->token_arr[1]);
	if (global_args->stack_head)
	{
		(*stack)->next = global_args->stack_head;
		global_args->stack_head->prev = *stack;
	}
	global_args->stack_head = *stack;
	global_args->stack_len += 1;
}


/**
 * is_num - Check if a string represents a valid integer
 * @str: The input string to be checked
 * @str: The string to be checked for integer validity.
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */

int is_num(char *str)
{
	int i = 0;
	int length = 0;

	if (str == NULL || *str == '\0')
		return (0);

	if (str[i] == '-')
	{
		i++;
		length++;
	}

	while (isdigit(str[i]))
	{
		i++;
		length++;
	}

	return (length > 0 && str[i] == '\0');
}



