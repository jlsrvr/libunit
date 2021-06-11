#include "libunit.h"

static void close_files(FILE *ptr1, FILE *ptr2)
{
		fclose(ptr1);
		fclose(ptr2);
}

static void add_line(t_line **line_lst, int line_no)
{
	t_line *temp;
	t_line *last;
	t_line *new;

	temp = *line_lst;
	last = NULL;
	while (temp)
	{
		if (temp->line_no == line_no)
			return ;
		last = temp;
		temp = temp->next;
	}
	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new->line_no = line_no;
	new->next = NULL;
	if (!temp && !last)
		*line_lst = new;
	else
		last->next = new;
}

static int open_files(char *file_exp, char *file_got, FILE **ptr_exp, FILE **ptr_got)
{
	*ptr_exp = fopen(file_exp, "r");
	if (!*ptr_exp)
		return (1);
	*ptr_got = fopen(file_got, "r");
	if (!*ptr_got)
	{
		fclose(*ptr_exp);
		return (1);
	}
	return (0);
}

static void print_line(int line_no, int *actual_no, FILE *file_stream, int expec)
{
	char *line;

	line = NULL;
	while (*actual_no <= line_no)
	{
		free(line);
		line = NULL;
		get_next_line(fileno(file_stream), &line);
		(*actual_no)++;
	}
	if (expec)
		printf(GREEN"-");
	else
		printf(RED"+");
	printf("%s\n"RESET, line);
	free(line);
}

static void print_diff(t_line **line_lst, char *file_exp, char *file_got)
{
	t_line *temp;
	t_line *prev;
	FILE *ptr_exp;
	FILE *ptr_got;
	int actual_line;
	int act_line;

	ptr_got = NULL;
	ptr_exp = NULL;
	if (open_files(file_exp, file_got, &ptr_exp, &ptr_got))
		return ;
	temp = *line_lst;
	printf("\nDiff exp-%s got-%s\n", file_exp, file_got);
	printf("--- exp-%s\n+++ got-%s\n", file_exp, file_got);
	actual_line = 1;
	act_line = 1;
	while (temp)
	{
		printf("Line %d:\n", actual_line);
		print_line(temp->line_no, &actual_line, ptr_exp, 1);
		print_line(temp->line_no, &act_line, ptr_got, 0);
		prev = temp;
		temp = temp->next;
		free(prev);
	}
	close_files(ptr_exp, ptr_got);
}

int file_diff_print(char *file_exp, char *file_got)
{
	FILE *ptr_exp;
	FILE *ptr_got;
	char one;
	char two;
	t_line *line_lst;
	int line;

	line_lst = NULL;
	ptr_got = NULL;
	ptr_exp = NULL;
	if (open_files(file_exp, file_got, &ptr_exp, &ptr_got))
		return (1);
	line = 1;
	do
	{
		one = fgetc(ptr_exp);
		two = fgetc(ptr_got);
		if (one == '\n')
			line++;
		if (one != two)
			add_line(&line_lst, line);
	} while (one != EOF && two != EOF);
	close_files(ptr_exp, ptr_got);
	if (one == EOF && two == EOF && !line_lst)
		return (0);
	print_diff(&line_lst, file_exp, file_got);
	return (1);
}

int file_diff(char *file_exp, char *file_got)
{
	FILE *ptr_exp;
	FILE *ptr_got;
	char one;
	char two;

	ptr_exp = fopen(file_exp, "r");
	if (!ptr_exp)
		return (1);
	ptr_got = fopen(file_got, "r");
	if (!ptr_got)
	{
		fclose(ptr_exp);
		return (1);
	}
	do
	{
		one = fgetc(ptr_exp);
		two = fgetc(ptr_got);
		if (one != two)
		{
			close_files(ptr_exp, ptr_got);
			return (1);
		}
	} while (one != EOF && two != EOF);
	close_files(ptr_exp, ptr_got);
	if (one == EOF && two == EOF)
		return (0);
	return (1);
}
