#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void f_open_f(char *f_name);
int p_line(char *buffer, int l_num, int f);
void r_file(FILE *);
int len_chars(FILE *);
void f_func(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void print_s(stack_t **, unsigned int);
void add_to_s(stack_t **, unsigned int);
void add_to_q(stack_t **, unsigned int);

void c_function(op_func, char *, char *, int, int);

void print_to_top(stack_t **, unsigned int);
void pop_to_top(stack_t **, unsigned int);
void f_nop(stack_t **, unsigned int);
void f_swap_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void f_add_(stack_t **, unsigned int);
void f_sub_(stack_t **, unsigned int);
void f_div_(stack_t **, unsigned int);
void f_mul_(stack_t **, unsigned int);
void f_mod_(stack_t **, unsigned int);

/*String operations*/
void p_char(stack_t **, unsigned int);
void p_str(stack_t **, unsigned int);
void _rotl(stack_t **, unsigned int);

/*Error hanlding*/
void error(int has, ...);
void _error(int has, ...);
void s_error(int has, ...);
void _rotr(stack_t **, unsigned int);

#endif
