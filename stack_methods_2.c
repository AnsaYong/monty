#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: reference (pointer to pointer) to the stack
 * @line_number: integer (line number)
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	unsigned int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * _add - adds the top two elements of the stack
 * @stack: reference (pointer to pointer) to the stack
 * @line_number: integer (line number)
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;

	/* Pop the top element (the first element) */
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * _nop - does nothing (nop)
 * @stack: reference (pointer to pointer) to the stack (unused)
 * @line_number: integer (unused)
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
