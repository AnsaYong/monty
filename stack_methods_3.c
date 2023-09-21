#include "monty.h"

/**
 * _mul - multiplies the second top element of the stack with the
 * top element of the stack
 * @stack: reference (pointer to pointer) to the stack
 * @line_number: integer (line number)
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;

	/* Pop the top element (the first element) */
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * _mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack
 * @stack: reference (pointer to pointer) to the stack
 * @line_number: integer (line number)
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: dvision by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;

	/* Pop the top element (the first element) */
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
