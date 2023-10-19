#include "monty.h"

/**
 * p_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln_n: Interger representing the line number of of the opcode.
 */
void p_str(stack_t **stack, __attribute__((unused))unsigned int ln_n)
{
	int as;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		as = tmp->n;
		if (as <= 0 || as > 127)
			break;
		printf("%c", as);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * p_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void p_char(stack_t **stack, unsigned int l_num)
{
	int as;

	if (stack == NULL || *stack == NULL)
		s_error(11, l_num);

	as = (*stack)->n;
	if (as < 0 || as > 127)
		s_error(10, l_num);
	printf("%c\n", as);
}
/**
 * _rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: Interger representing the line number of of the opcode.
 */

void _rotr(stack_t **stack, __attribute__((unused))unsigned int l_n)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}

/**
 * _rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: Interger representing the line number of of the opcode.
 */
void _rotl(stack_t **stack, __attribute__((unused))unsigned int l_n)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
