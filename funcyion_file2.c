#include "monty.h"

/**
 * f_nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void f_nop(stack_t **stack, unsigned int l_num)
{
	(void)stack;
	(void)l_num;
}

/**
 * f_swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void f_swap_nodes(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_error(8, l_num, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
/**
 * f_div_ - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void f_div_(stack_t **stack, unsigned int l_num)
{
	int summe;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_error(8, l_num, "div");

	if ((*stack)->n == 0)
		_error(9, l_num);
	(*stack) = (*stack)->next;
	summe = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = summe;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * f_sub_ - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void f_sub_(stack_t **stack, unsigned int l_num)
{
	int summe;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		_error(8, l_num, "sub");


	(*stack) = (*stack)->next;
	summe = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = summe;
	free((*stack)->prev);
}
/**
 * f_add_ - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void f_add_(stack_t **stack, unsigned int l_num)
{
	int summe;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_error(8, l_num, "add");

	(*stack) = (*stack)->next;
	summe = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = summe;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
