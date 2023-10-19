#include "monty.h"

/**
 * add_to_s - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln_n: Interger representing the line number of of the opcode.
 */
void add_to_s(stack_t **new_node, __attribute__((unused))unsigned int ln_n)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}
/**
 * print_to_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void print_to_top(stack_t **stack, unsigned int l_num)
{
	if (stack == NULL || *stack == NULL)
		_error(6, l_num);
	printf("%d\n", (*stack)->n);
}

/**
 * print_s - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: line number of  the opcode.
 */
void print_s(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	(void) l_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_to_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void pop_to_top(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		_error(7, l_num);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
