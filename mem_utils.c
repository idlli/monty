#include "monty.h"

static void *g_memarray[MAX_MEMORY_CAPACITY];
static int g_memlen;

/**
 * alloc_mem - allocates memory on the heap and kerps track of it
 *
 * @size: the amount of bytes to allocate
 *
 * Return: an address to the allocated memory
 */
void *alloc_mem(unsigned long size)
{
	void *mem = malloc(size);

	if (mem == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_program(EXIT_FAILURE);
	}

	g_memarray[g_memlen++] = mem;

	return (mem);
}

/**
 * is_allocated - determines whether a value exists in the global memory array
 *
 * @mem: the value yo look for
 *
 * Return: the index of the value if found, -1 elsewise
 */
int is_allocated(const void *mem)
{
	int i;

	for (i = 0; i < g_memlen; i++)
		if (g_memarray[i] == mem)
			return (i);

	return (-1);
}

/**
 * add_allocated - adds an address to be tracked
 *
 * @mem: address of the memory
 */
void add_allocated(void *mem)
{
	int i, pos = -1;

	for (i = 0; i < g_memlen; i++)
	{
		if (g_memarray[i] == mem)
			return;
		if (g_memarray[i] == NULL)
			pos = i;
	}

	if (pos != -1)
		g_memarray[pos] = mem;
	else
		g_memarray[g_memlen++] = mem;
}

/**
 * free_mem - frees a memory address from the heap only it's if not freed yet
 *
 * @mem: the address to frer
 */
void free_mem(void *mem)
{
	int i = is_allocated(mem);

	if (i != -1)
	{
		free(mem);
		g_memarray[i] = NULL;
	}
}

/**
 * exit_program - frees all memory then exits the program
 *
 * @code: the exit code of the program
 */
void exit_program(int code)
{
	int i;

	for (i = 0; i < g_memlen; i++)
		if (g_memarray[i] != NULL)
		{
			free(g_memarray[i]);
			g_memarray[i] = NULL;
		}
	g_memlen = 0;

	if (*get_inp_file())
		fclose(*get_inp_file());

	if (*get_inp_line())
		free(*get_inp_line());

	exit(code);
}
