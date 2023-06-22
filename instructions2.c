#include "monty.h"

/**
 * add - the "add" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void add(stack_t **stack, unsigned int line_number)
{
	int first, second;

	if (stack == NULL || *stack == NULL || len_stack(*stack) < 2)
	{
		fprintf(stderr,
			"L%u: can't add, stack too short\n", line_number);
		exit_program(EXIT_FAILURE);
	}

	first = pop_stack(stack);
	second = pop_stack(stack);

	push_stack(stack, first + second);
}

/**
 * nop - the "nop" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - the "sub" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int first, second;

	if (stack == NULL || *stack == NULL || len_stack(*stack) < 2)
	{
		fprintf(stderr,
			"L%u: can't sub, stack too short\n", line_number);
		exit_program(EXIT_FAILURE);
	}

	first = pop_stack(stack);
	second = pop_stack(stack);

	push_stack(stack, second - first);
}

/**
 * _div - the "div" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int first, second;

	if (stack == NULL || *stack == NULL || len_stack(*stack) < 2)
	{
		fprintf(stderr,
			"L%u: can't div, stack too short\n", line_number);
		exit_program(EXIT_FAILURE);
	}

	first = pop_stack(stack);
	second = pop_stack(stack);

	if (first == 0)
	{
		fprintf(stderr,
			"L%u: division by zero\n", line_number);
		exit_program(EXIT_FAILURE);
	}

	push_stack(stack, second / first);
}

/**
 * mul - the "mul" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int first, second;

	if (stack == NULL || *stack == NULL || len_stack(*stack) < 2)
	{
		fprintf(stderr,
			"L%u: can't mul, stack too short\n", line_number);
		exit_program(EXIT_FAILURE);
	}

	first = pop_stack(stack);
	second = pop_stack(stack);

	push_stack(stack, first * second);
}
