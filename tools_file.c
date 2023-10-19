#include "monty.h"

/**
 * f_open_f - opens a file
 * @f_name: the file namepath
 * Return: void
 */

void f_open_f(char *f_name)
{
	FILE *food = fopen(f_name, "r");

	if (f_name == NULL || food == NULL)
		error(2, f_name);

	read_file(fd);
	fclose(food);
}


/**
 * r_file - reads a file
 * @food: pointer to file descriptor
 * Return: void
 */

void r_file(FILE *food)
{
	int l_num, f = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (l_num = 1; getline(&buffer, &len, food) != -1; l_num++)
	{
		f = parse_line(buffer, l_num, f);
	}
	free(buffer);
}


/**
 * p_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @l_num: line number
 * @f:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int p_line(char *buffer, int l_num, int f)
{
	char *opcode, *val;
	const char *del = "\n ";

	if (buffer == NULL)
		error(4);

	opcode = strtok(buffer, del);
	if (opcode == NULL)
		return (f);
	value = strtok(NULL, del);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, val, l_num, f);
	return (f);
}

/**
 * f_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @val: argument of opcode
 * @f:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void f_func(char *opcode, char *val, int ln, int f)
{
	int i;
	int fla;

	instruction_t func_list[] = {
		{"push", add_to_s},
		{"pall", print_s},
		{"pint", print_to_top},
		{"pop", pop_to_top},
		{"nop", f_nop},
		{"swap", f_swap_nodes},
		{"add", f_add_},
		{"sub", f_sub_},
		{"div", f_div_},
		{"mul", f_mul_},
		{"mod", f_mod_},
		{"pchar", p_char},
		{"pstr", p_str},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (fla = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			c_function(func_list[i].f, opcode, val, ln, f);
			fla = 0;
		}
	}
	if (fla == 1)
		error(3, ln, opcode);
}


/**
 * c_function - Calls the required function.
 * @fun: Pointer to the function that is about to be called.
 * @o: string representing the opcode.
 * @vall: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @f: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void c_function(op_func fun, char *o, char *vall, int ln, int f)
{
	stack_t *node;
	int fla;
	int s;

	fla = 1;
	if (strcmp(o, "push") == 0)
	{
		if (vall != NULL && vall[0] == '-')
		{
			vall = vall + 1;
			fla = -1;
		}
		if (vall == NULL)
			error(5, ln);
		for (s = 0; vall[s] != '\0'; i++)
		{
			if (isdigit(val[s]) == 0)
				error(5, ln);
		}
		node = create_node(atoi(val) * fla);
		if (f == 0)
			fun(&node, ln);
		if (f == 1)
			add_to_q(&node, ln);
	}
	else
		fun(&head, ln);
}
