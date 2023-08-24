#include "monty.h"

/**
* run - execute the opcode.
* @head: head linked list - stack.
* @nbLine: the number of line.
* @file: poiner to monty file.
* @content: line content.
* Return: no return.
*/
int run(char *content, stack_t **head, unsigned int nbLine, FILE *file)
{
	instruction_t op_stk[] = {
				{"push", push}, {"pall", pall}, {"pint", pint},
				{"pop", pop}, {"swap", swap}, {"add", add},
				{"nop", nop}, {"sub", sub}, {"div", div_fun},
				{"mul", mul}, {"mod", mod}, {"comments", comments},
				{"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl},
				{"rotr", rotr}, {"queue", queue}, {"stack", stack},
				{NULL, NULL}
				};
	unsigned int x = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (op_stk[x].opcode && op)
	{
		if (strcmp(op, op_stk[x].opcode) == 0)
		{ op_stk[x].f(head, nbLine);
			return (0);
		}
		x++; }
	if (op && op_stk[x].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", nbLine, op);
		fclose(file);
		free(content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	return (1);
}
