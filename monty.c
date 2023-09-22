#include "monty.h"

/* Declare the global stack pointer as extern */
stack_t *stack = NULL;

/**
 * monty_interpreter - reads and executes each line of code
 * in the provided monty bytecode file
 * @f_ptr: file pointer of the opened file
 */
void monty_interpreter(FILE *f_ptr)
{
	char opcode[MAX_WORD_LENGTH], opcode_data[MAX_WORD_LENGTH];
	int word_count, line_numb = 0;
	char line[MAX_LINE_LENGTH];
	void (*op_func)(stack_t **stack, unsigned int line_number);

	/* loop to read each line in the file */
	while (fgets(line, sizeof(line), f_ptr) != NULL)
	{
		line_numb++;

		if (line[0] == '#')	/* handle comments */
			continue;

		/* get opcode and its data from each line */
		word_count = sscanf(line, "%s %s", opcode, opcode_data);
		if (word_count == 1 || word_count == 2)
		{
			op_func = get_opcode(opcode);
			if (op_func == NULL)	/* check if opcode is valid */
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
						line_numb, opcode);
				exit(EXIT_FAILURE);
			}

			/* execute opcode only if opcode_data is numeric and not 0 */
			op_func(&stack, atoi(opcode_data));

			/* reset opcode and opcode_data */
			strcpy(opcode, "");
			strcpy(opcode_data, "");
		}
		else
		{
			strcpy(opcode, "");
			strcpy(opcode_data, "");
		}
	}
	free_stackt(stack);
	stack = NULL;
}

/**
 * get_opcode - checks if the provided opcode is valid
 * @s: opcode from the associated monty bytecode file
 *
 * Return: function pointer to execute the opcode if present, NULL otherwise
 */

void (*get_opcode(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"div", _div},
		{"sub", _sub},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};
	size_t i;

	/* iterate through all elements of the opcodes array of structs */
	i = 0;
	while (opcodes[i].opcode != NULL)
	{
		/* check if opcode is part of the valid opcodes */
		if (strcmp(opcodes[i].opcode, s) == 0)
			return (opcodes[i].f);
		i++;
	};

	return (NULL);
}


