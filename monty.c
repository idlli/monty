#define _GNU_SOURCE
#include "monty.h"

/**
 * execute_instruction - executes an instruction
 *
 * @instruction_list: list of available instructions
 * @size: size of instruction list
 * @cmd: the command from the user
 * @stack: the main stack
 * @line_number: number of current line
 */
void execute_instruction(
	const instruction_t *instruction_list,
	unsigned long size, const char *cmd,
	stack_t **stack,
	unsigned int line_number)
{
	unsigned int i;

	for (i = 0; i < size; i++)
	{
		if (strcmp(instruction_list[i].opcode, cmd) == 0)
		{
			instruction_list[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, cmd);
	exit_program(EXIT_FAILURE);
}

/**
 * fill_instructions - fills all available instructions
 *
 * @list: the instruction array
 */
void fill_instructions(instruction_t list[])
{
	char *names[] = {
		"push", "pall", "pint",
		"pop", "swap", "add",
		"nop", "sub", "div",
		"mul", "mod"
	};
	void (*funcs[])(stack_t **, unsigned int) = {
		push, pall, pint,
		pop, swap, add,
		nop, sub, _div,
		mul, mod
	};
	unsigned int i;

	for (i = 0; i < sizeof(names) / sizeof(*names); i++)
	{
		list[i].opcode = names[i];
		list[i].f = funcs[i];
	}
}

/**
 * main - entry point of the program
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE elsewise
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	instruction_t instruction_list[11];
	FILE *file;
	size_t line_alloc = 0, line_number = 0;
	ssize_t line_len;
	char *line = NULL, *cmd = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit_program(EXIT_FAILURE);
	}

	*get_inp_file() = file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit_program(EXIT_FAILURE);
	}

	fill_instructions(instruction_list);

	while ((line_len = getline(&line, &line_alloc, file)) != -1)
	{
		line_number++;
		*get_inp_line() = line;
		cmd = strtok(line, DELIMETER);
		if (cmd && cmd[0] == '#')
			continue;
		if (cmd)
			execute_instruction(instruction_list,
				sizeof(instruction_list) / sizeof(instruction_t),
				cmd, &stack, line_number);
	}

	*get_inp_line() = line;
	exit_program(EXIT_SUCCESS);
	return (0);
}
