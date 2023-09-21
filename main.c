#include "monty.h"

/**
 * main - monty language interprter entry point
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS
 */

int main(int argc, char **argv)
{
	FILE *fp;

	/* handle error if more than one argument (filename) is given */
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open the file and handle error on failure */
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* call function to execute code in the opened file */
	monty_interpreter(fp);

	fclose(fp);

	return (EXIT_SUCCESS);
}
