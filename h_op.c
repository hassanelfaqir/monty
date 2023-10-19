#include "monty.h"


/**
 * f_mod_ - Adds the top two elements of the stack.
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @l_num: Interger representing the line number of of the opcode.
 */
void f_mod_(stack_t **stack, unsigned int l_num)
{
	int summe;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		_error(8, l_num, "mod");

	if ((*stack)->n == 0)
		_error(9, l_num);
	(*stack) = (*stack)->next;
	summe = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = summe;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * f_mul_ - Adds the top two elements of the stack.
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @l_num: Interger representing the line number of of the opcode.
 */

void f_mul_(stack_t **stack, unsigned int l_num)
{
	int summe;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_error(8, l_num, "mul");

	(*stack) = (*stack)->next;
	summe = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = summe;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
