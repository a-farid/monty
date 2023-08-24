#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
char  *clean_line(char *content);
void stack_push(stack_t **head, unsigned int number);
ssize_t getstdin(char **lineptr, int file);
void stack_pall(stack_t **head, unsigned int number);
int execute_opcode(char *content, stack_t **head, unsigned int counter, FILE *file);
void stack_free(stack_t *head);
void stack_pint(stack_t **head, unsigned int number);
void stack_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void stack_pop(stack_t **head, unsigned int counter);
void stack_add(stack_t **head, unsigned int counter);
void stack_nop(stack_t **head, unsigned int counter);
void stack_pstr(stack_t **head, unsigned int counter);
void stack_sub(stack_t **head, unsigned int counter);
void stack_mul(stack_t **head, unsigned int counter);
void stack_swap(stack_t **head, unsigned int counter);
void stack_mod(stack_t **head, unsigned int counter);
void stack_div(stack_t **head, unsigned int counter);
void node_add(stack_t **head, int n);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
void stack_pchar(stack_t **head, unsigned int counter);
void stack_rotl(stack_t **head, unsigned int counter);
void print_stack(stack_t **head, unsigned int counter);
int run(char *content, stack_t **head, unsigned int nbLine, FILE *file);
void stack_queue(stack_t **head, unsigned int counter);
void que_add(stack_t **head, int n);
#endif

