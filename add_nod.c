#include "monty.h"
/**
 * stack_add - adds the top two elements of the stack.
 * @head: the stack head.
 * @counter: the line_number.
 * Return: no return.
*/
void stack_add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int l = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

#include "monty.h"
/**
 * stack_queue - prints the top stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void stack_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * que_add - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void que_add(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}

#include "monty.h"
/**
 * node_add - add node to the stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void node_add(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

