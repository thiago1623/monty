#include "monty.h"
/**
 * create_node - function that create a new node
 * @n_line_number: parameters
 * Return: new_node
 */
stack_t *create_node(int n_line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)/*If you can’t malloc anymore*/
	{
		dprintf(STDERR_FILENO, "Error: malloc failed");
		free(g_v.buffer);
		free_dlistint(&g_v.head);
		exit(EXIT_FAILURE);
	}

	if (!n_line_number)/*If it is not the data*/
	{
		free(new_node);
		exit(EXIT_FAILURE);
	}

	new_node->n = n_line_number;/*pointer to data n*/
	new_node->next = NULL;/*pointer to next address*/
	new_node->prev = NULL;/*pointer to previous address*/

	return (new_node);/*return the new_node*/
}
