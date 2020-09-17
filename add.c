#include "monty.h"
/**
* add_element - Plus of two dates in two nodes.
* @head: Pointer to list.
* @line_number: Number of line in the file.
*/
void add_element(stack_t **head, unsigned int line_number)
{

	if (!*(head) || !(*head)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
			line_number);
		fclose(g_v.fd);
		free(g_v.buffer);
		free_dlistint(&g_v.head);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n = (*head)->next->n + (*head)->n;
	pop_element(head, line_number);
}
