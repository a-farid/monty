#include "monty.h"
/**
 * execute_opcode - executes the opcode
 * @stack: head linked list - stack.
 * @counter: line_counter.
 * @file: poiner to monty file.
 * @content: line content.
 * Return: no return.
 */
int execute_opcode(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
  instruction_t opst[] = {
			  {"push", stack_push},
			  {"pall", stack_pall},
			  {"pint", stack_pint},
			  {"pop", stack_pop},
			  {"swap", stack_swap},
			  {"add", stack_add},
			  {"nop", stack_nop},
			  {"sub", stack_sub},
			  {"div", stack_div},
			  {"mul", stack_mul},
			  {"mod", stack_mod},
			  {"pchar", stack_pchar},
			  {"pstr", stack_pstr},
			  {"rotl", stack_rotl},
			  {"rotr", stack_rotr},
			  {"queue", stack_queue},
			  {"stack", print_stack},
			  {NULL, NULL}
  };
  char *op;
  unsigned int x = 0;

  op = strtok(content, " \n\t");
  if (op && op[0] == '#')
    return (0);
  bus.arg = strtok(NULL, " \n\t");
  while (opst[x].opcode && op)
    {
      if (strcmp(op, opst[x].opcode) == 0)
	{opst[x].f(stack, counter);
	  return (0);
	}
      x++;
    }
  if (op && opst[x].opcode == NULL)
    { fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
      fclose(file);
      free(content);
      stack_free(*stack);
      exit(EXIT_FAILURE); }
  return (1);
}
