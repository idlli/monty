#include "monty.h"

/**
 * push - the "push" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int i;

	arg = strtok(NULL, DELIMETER);

	if (arg == NULL || arg[0] == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit_program(EXIT_FAILURE);
	}

	for (i = 0; arg[i]; i++)
		if (!(('0' <= arg[i] && arg[i] <= '9')
					|| (i == 0 && arg[i] == '-')))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit_program(EXIT_FAILURE);
		}

	push_stack(stack, atoi(arg));
}

/**
 * pall - the "pall" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_stack(*stack);
}

/**
 * pint - the "pint" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit_program(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - the "pop" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit_program(EXIT_FAILURE);
	}

	pop_stack(stack);
}

/**
 * swap - the "swap" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int first, second;

	if (stack == NULL || *stack == NULL || len_stack(*stack) < 2)
	{
		fprintf(stderr,
			"L%u: can't swap, stack too short\n", line_number);
		exit_program(EXIT_FAILURE);
	}

	first = pop_stack(stack);
	second = pop_stack(stack);

	push_stack(stack, first);
	push_stack(stack, second);
}
