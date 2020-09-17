#include "monty.h"
/**
 * get_match - function that create a new node
 * @line_number: parameters
 * @head: double linked list
 * @buffer: the buffer
 */
void get_match(char **buffer, stack_t **head, unsigned int line_number)
{
	unsigned int count = 0;/*iterator for the loop*/
	char *token;/*variable for the separation of the tokens*/

	instruction_t match[] = {/*structure to obtain each function*/
		{"push", push_element},
		{"pall", pall_element},
		{"pint", pint_element},
		{"pop", pop_element},
		{"swap", swap_element},
		{"add", add_element},
		{"nop", nop},
		{NULL, NULL}
	};
	token = strtok(*buffer, " \n\t");/*separation of the tokens*/
	while (count < 7)/*loop for the structure match*/
	{
		if (strcmp(token, match[count].opcode) == 0)
		{/*compare if make match*/
			match[count].f(head, line_number);
			return;
		}

		/*
		 *if (strcmp(token, match[count].opcode) == 0)
		 *{
		 *	op_code.opcode = match[count].opcode;
		 *	dprintf(STDERR_FILENO, "L<%u>: unknown instruction <%s>\n",
		 *		line_number, op_code.opcode);
		 *	free(g_v.buffer);
		 *	exit(EXIT_FAILURE);
		 *	return;
		 *}
		*/
		count++;
	}
}
