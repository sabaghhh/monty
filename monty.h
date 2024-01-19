#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct arguments_s - Structure to store program arguments
 * @f_content: File content represented by a FILE pointer
 * @line: A string representing a line of content
 * @line_number: The line number in the file
 * @token_arr: An array of strings representing tokens
 * @num_tokens: The number of tokens in the array
 * @stack_head: A pointer to the head of a stack structure
 * @stack_len: The length of the stack
 * @instr_ptr: A pointer to an instruction structure
 *
 * Description: This structure is designed to store various program arguments
 */
typedef struct arguments_s
{
	FILE *f_content;
	char *line;
	unsigned int line_number;
	char **token_arr;
	int num_tokens;
	stack_t *stack_head;
	int stack_len;
	instruction_t *instr_ptr;
} arguments_t;

extern arguments_t *global_args;

int main(int argc, char **argv);
void get_content(char *fileName);
void get_tokens(void);
void get_instruction(void);
void execute_instruction(void);
void malloc_failed(void);
void free_tokens(void);
void close_stream(void);
void free_arguments(void);
void free_stack(stack_t *head);


int is_num(char *str);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void my_div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
