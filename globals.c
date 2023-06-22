#include "monty.h"

/**
 * get_inp_file - the file that is being read
 *
 * Return: a pointer to the input file
 */
FILE **get_inp_file(void)
{
	static FILE *s_file;

	return (&s_file);
}

/**
 * get_inp_line - the current line that is being processed
 *
 * Return: a pinter to the current line
 */
char **get_inp_line(void)
{
	static char *s_line;

	return (&s_line);
}
