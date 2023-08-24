#include "monty.h"
/**
  *stack_rotl- rotates the top stack
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void stack_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}

/**
  *stack_rotr- rotates the stack to bottom
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void stack_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}

/**
 * stack_swap - adds the top stack two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void stack_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}

/**
 * print_stack - prints the top of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void print_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}

/**
  *stack_nop- nothing
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void stack_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
