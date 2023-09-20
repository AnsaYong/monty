#include "monty.h"

/**
 * _push - adds an element to the top of a stack
 * @stack: reference (pointer to pointer) to the stack
 * @line_number: value (integer) to push to the stack
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (line_number < 48 && line_number > 57)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* insert the required data */
	new_node->n = line_number;

	/* make next of the new node the head and its prev NULL */
	new_node->prev = NULL;
	new_node->next = *stack;

	/* make prev of the current head point to new node */
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	/* Update the global stack pointer by point head to new node */
	*stack = new_node;
}

/**
 * _pall - prints all the values on the stack, starting from the top
 * @stack: reference (pointer to pointer) to the stack
 * @line_number: integer (unused)
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;	/* unused parameter */

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * free_stackt - frees a doubly linked stack
 * @stack: reference (pointer) to the start of the stack
 */
void free_stackt(stack_t *stack)
{
	stack_t *temp;
	stack_t *temp2 = NULL;

	temp = stack;

	while (temp != NULL)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}

	stack = NULL;
}
