#include "monty.h"

globals_variables g_v;
instruction_t op_code;
/**
 * main - Interpreter of the Monty Language
 * @argc: argument count
 * @argv: the list of arguments
 * Return: 0 if passed
 */
int main(int argc, char *argv[])
{
	char *pathname = argv[1]; /*argument for the file*/
	unsigned int iterator;/*iterator for the loop*/
	size_t size_line = sizeof(g_v.fd);/*size of the fd*/
	ssize_t  sts_read = 0;/*variable for the getline*/

	g_v.head = NULL;/*globals_variables*/
	g_v.buffer = NULL;/*globals_variables*/
	g_v.fd = NULL;/*globals_variables*/

	if (argc != 2 || pathname == NULL) /*If the user does not give any file*/
	{/*or more than one argument to your program*/
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	g_v.fd = fopen(pathname, "r");

	if (!g_v.fd)/*it’s not possible to open the file,*/
	{
		dprintf(STDERR_FILENO, "Error: Can't open file <%s>\n", pathname);
		exit(EXIT_FAILURE);
	}
	for (iterator = 1; (sts_read = getline(&g_v.buffer, &size_line, g_v.fd))
		    != -1; iterator++)
	{/*itera line for line in the fd*/
		get_match(&g_v.buffer, &g_v.head, iterator);
	}
	fclose(g_v.fd);
	free(g_v.buffer);
	free_dlistint(&g_v.head);
	return (0);
}
