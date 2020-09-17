#include "monty.h"

/**
 * sub_stack - sub the last two elements of the stack
 * @stack: the stack
 * @line_number: line of my file
 * Return: void
 */

void sub_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	stack_t *aux = *stack;
	int count = 0;

	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n",
			line_number);
		free_dlistint(stack);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	aux = aux->next;
	aux->n = node->next->n - node->n;
	free(node);
	aux->prev = NULL;
	*stack = aux;
}
/**
 * div_stack - The opcode nop doesn’t do anything.
 * @stack: doubly linked list.
 * @line_number: line of file.
 */
void div_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	stack_t *aux = *stack;
	int count = 0;

	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	if (count < 2)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't div, stack too short\n", line_number);
		free_dlistint(stack);
		exit(EXIT_FAILURE);
	}
	if (aux->n == 0)
	{
		dprintf(STDERR_FILENO,
			"L%u: division by zero\n", line_number);
		free_dlistint(stack);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	aux = aux->next;
	aux->n = node->next->n / node->n;
	free(node);
	aux->prev = NULL;
	*stack = aux;
}

/**
 * mul_stack - mul the last two elements of the stack
 * @stack: the stack
 * @line_number: line of my file
 * Return: void
 */

void mul_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	stack_t *aux = *stack;
	int count = 0;

	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n",
			line_number);
		free_dlistint(stack);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	aux = aux->next;
	/* sumamos los 2 primeros nodos*/
	aux->n = node->next->n * node->n;
	/*elimino un node que multiplique*/
	free(node);
	aux->prev = NULL;
	*stack = aux;
}
