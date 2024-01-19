#include "monty.h"

/**
 * sub - substract the top two values on the stack
 * @stack: Double pointer to the head of the stack (unused)
 * @line_number: Line number in the source file
 * Return: No explicit return value. Exits the program with EXIT_FAILURE
 *           upon error.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp1, *temp2;

	(void) stack;

	if (global_args->stack_len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		close_stream();
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}

	temp1 = global_args->stack_head;
	temp2 = temp1->next;
	temp2->n = temp2->n - temp1->n;
	temp = global_args->stack_head;
	global_args->stack_head = temp->next;
	free(temp);
	global_args->stack_len -= 1;
}


/**
 * my_div - divide the top two values on the stack
 * @stack: Double pointer to the head of the stack (unused)
 * @line_number: Line number in the source file
 * Return: No explicit return value. Exits the program with EXIT_FAILURE
 *           upon error.
 */
void my_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp1, *temp2;

	(void) stack;

	if (global_args->stack_len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		close_stream();
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}

	temp1 = global_args->stack_head;
	temp2 = temp1->next;
	if (temp1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		close_stream();
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}
	temp2->n = temp2->n / temp1->n;
	temp = global_args->stack_head;
	global_args->stack_head = temp->next;
	free(temp);
	global_args->stack_len -= 1;
}



/**
 * mul - multiply the top two values on the stack
 * @stack: Double pointer to the head of the stack (unused)
 * @line_number: Line number in the source file
 * Return: No explicit return value. Exits the program with EXIT_FAILURE
 *           upon error.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp1, *temp2;

	(void) stack;

	if (global_args->stack_len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		close_stream();
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}

	temp1 = global_args->stack_head;
	temp2 = temp1->next;
	temp2->n = temp2->n * temp1->n;
	temp = global_args->stack_head;
	global_args->stack_head = temp->next;
	free(temp);
	global_args->stack_len -= 1;
}

/**
 * mod - calculate the remender of division
 * @stack: Double pointer to the head of the stack (unused)
 * @line_number: Line number in the source file
 * Return: No explicit return value. Exits the program with EXIT_FAILURE
 *           upon error.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp1, *temp2;

	(void) stack;

	if (global_args->stack_len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		close_stream();
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}

	temp1 = global_args->stack_head;
	temp2 = temp1->next;
	if (temp1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		close_stream();
		free_tokens();
		free_arguments();
		exit(EXIT_FAILURE);
	}
	temp2->n = temp2->n % temp1->n;
	temp = global_args->stack_head;
	global_args->stack_head = temp->next;
	free(temp);
	global_args->stack_len -= 1;
}

