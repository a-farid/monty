#include "monty.h"
/**
 * stack_div - divides the top two stack elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void stack_div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

/**
 * stack_mul - multiplies the top two stack elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void stack_mul(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

/**
 * stack_mod - computes the modulos of the second
 * top element of the stack by the first element of the stack.
 * @head: stack head.
 * @counter: line_number.
 * Return: no return.
*/
void stack_mod(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
