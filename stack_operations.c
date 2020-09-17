#include "monty.h"
/**
 * push_element - functions that push elements in my lsit
 * @line_number: parameters
 * @head:  double linked list
 */
void push_element(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL, *tmp = NULL;
	char *clear_number = NULL;
	int number;

	clear_number = strtok(NULL, " \n\t");
	if (!clear_number)
	{/*is not an integer or if there is no argument given to push*/
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
			line_number);
		fclose(g_v.fd);
		free(g_v.buffer);
		free_dlistint(&g_v.head);
		exit(EXIT_FAILURE);
	}
	number = atoi(clear_number);
	if (number < 0 || !number)
	{/*is not an integer or if there is no argument given to push*/
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
			line_number);
		fclose(g_v.fd);
		free(g_v.buffer);
		free_dlistint(&g_v.head);
		exit(EXIT_FAILURE);
	}
	if (number >= 0)
	{
		if (!*head)/*If it doesn't exist head*/
		{
			new_node = create_node(number);
			*head = new_node;
		}
		else
		{
			new_node = create_node(number);
			tmp = *head;
			new_node->next = tmp;
			tmp->prev = new_node;
			*head = new_node;
		}
	}
}
/**
 * pall_element - Print list
 * @head: Double linked list
 * @line_number: File line execution
 */
void pall_element(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *head;

	if (!*head)
	{
		dprintf(STDERR_FILENO, "L%u: usage: pop integer\n",
			line_number);
		fclose(g_v.fd);
		free(g_v.buffer);
		exit(EXIT_FAILURE);
	}
	if (!tmp)
	{
		dprintf(STDERR_FILENO, "L%u: usage: tmp integer\n",
			line_number);
		fclose(g_v.fd);
		free(g_v.buffer);
		exit(EXIT_FAILURE);
	}
	while (tmp)
	{
		if (tmp->n >= 0)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}
}
/**
 * pint_element - Print last node
 * @head: Double linked list
 * @line_number: File line execution
 */
void pint_element(stack_t **head, unsigned int line_number)
{
	if (!*head)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint an empty stack\n",
			line_number);
		fclose(g_v.fd);
		free(g_v.buffer);
		free_dlistint(&g_v.head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop_element - Delete top of list
 * @head: Double linked list
 * @line_number: File line execution
 */
void pop_element(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!*head)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't pop an empty stack\n", line_number);
		fclose(g_v.fd);
		free(g_v.buffer);
		free_dlistint(&g_v.head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	tmp->prev = NULL;
	tmp->next = NULL;
	free(tmp);
}
/**
 * swap_element - Delete top of list
 * @head: Double linked list
 * @line_number: File line execution
 */
void swap_element(stack_t **head, unsigned int line_number)
{
	int cnt = 0;
	stack_t *tmp = *head;

	if (!tmp)
		return;
	while (tmp)
	{
		tmp = tmp->next;
		cnt++;
	}
	tmp = *head;
	if (cnt < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n",
			line_number);
		fclose(g_v.fd);
		free(g_v.buffer);
		free_dlistint(&g_v.head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	tmp->prev = *head;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
}
