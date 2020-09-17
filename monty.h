#ifndef Monty_H
#define Monty_H

/*Libraries*/
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern instruction_t op_code;
/**
 * struct globals_variables - golbal variables
 * @buffer: Getline buffer
 * @head: pointer to list
 * @fd: file descriptor
 */
typedef struct globals_variables
{
	char *buffer;
	stack_t *head;
	FILE *fd;
} globals_variables;

extern globals_variables g_v;

/*prototypes*/
void get_match(char **buffer, stack_t **head, unsigned int line_number);
stack_t *create_node(int n_line_number);
void push_element(stack_t **head, unsigned int line_number);
void pall_element(stack_t **head, unsigned int line_number);
void pint_element(stack_t **head, unsigned int line_number);
void pop_element(stack_t **head, unsigned int line_number);
void swap_element(stack_t **head, unsigned int line_number);
void add_element(stack_t **head, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void free_dlistint(stack_t **head);
void sub_stack(stack_t **stack, unsigned int line_number);
void div_stack(stack_t **stack, unsigned int line_number);
void mul_stack(stack_t **stack, unsigned int line_number);
void pchar_stack(stack_t **stack, unsigned int line_number);
void mod_stack(stack_t **stack, unsigned int line_number);

/*main*/
int main(int argc, char *argv[]);

#endif
