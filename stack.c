#include "monty.h"

/**
 * push_stack - appends a new element to the top of a stack
 *
 * @stack: the address of the stack
 * @n: the new value to be added
 *
 * Return: the newly created node
 */
stack_t *push_stack(stack_t **stack, int n)
{
	stack_t *new, *next = NULL, **head = stack;

	if (stack == NULL)
		return (NULL);

	while (*head != NULL)
	{
		next = *head;
		head = &(*head)->prev;
	}

	new = alloc_mem(sizeof(stack_t));
	new->n = n;
	new->prev = NULL;
	new->next = next;

	*stack = *head = new;

	return (new);
}


/**
 * print_stack - prints all elements in a stack
 *
 * @stack: the address of the stack
 */
void print_stack(const stack_t *stack)
{
	if (stack == NULL)
		return;

	while (stack->prev != NULL)
		stack = stack->prev;

	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}

/**
 * pop_stack - removes the element at the top of the stack
 *
 * @stack: the address of the stack
 *
 * Return: the value at the top of the stack
 */
int pop_stack(stack_t **stack)
{
	stack_t *new_head, *head;
	int n;

	if (stack == NULL || *stack == NULL)
		return (0);

	head = *stack;
	while (head->prev != NULL)
		head = head->prev;

	new_head = head->next;
	n = head->n;
	free_mem(head);
	if (new_head != NULL)
		new_head->prev = NULL;
	*stack = new_head;

	return (n);
}

/**
 * free_stack - frees a stack from heap memory
 *
 * @stack: the address of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *next = NULL, **head = stack;

	if (stack == NULL || *stack == NULL)
		return;

	while ((*head)->prev != NULL)
		head = &(*head)->prev;

	while (*head != NULL)
	{
		next = (*head)->next;
		free_mem(*head);
		*head = next;
	}

	*stack = NULL;
}

/**
 * len_stack - determines the length of a stack
 *
 * @stack: the address of the stack
 *
 * Return: the length of the stack
 */
unsigned int len_stack(stack_t *stack)
{
	unsigned int len = 0;

	if (stack == NULL)
		return (0);

	while (stack->prev != NULL)
		stack = stack->prev;

	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}

	return (len);
}
