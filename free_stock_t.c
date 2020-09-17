#include "monty.h"
/**
  * free_dlistint - frees a linked list
  * @head: head of the list
  */
void free_dlistint(stack_t **head)
{
	stack_t *tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->prev = NULL;
		tmp->next = NULL;
		free(tmp);
	}
}
