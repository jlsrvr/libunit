#include "libunit.h"

static int	close_files(FILE *ptr1, FILE *ptr2)
{
	fclose(ptr1);
	fclose(ptr2);
	return (FAILURE);
}

static void	add_line(t_line **line_lst, int line_no)
{
	t_line	*temp;
	t_line	*last;
	t_line	*new;

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

static int	open_files(char *file_exp, char *file_got,
		FILE **ptr_exp, FILE **ptr_got)
{
	*ptr_exp = fopen(file_exp, "r");
	if (!*ptr_exp)
		return (FAILURE);
	*ptr_got = fopen(file_got, "r");
	if (!*ptr_got)
	{
		fclose(*ptr_exp);
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	print_line(int line_no, int *actual_no,
		FILE *file_stream, int expec)
{
	char	*line;

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

static int	print_diff(t_line **line_lst, char *file_exp, char *file_got, int print)
{
	t_line	*temp;
	t_line	*prev;
	FILE	*ptr_exp;
	FILE	*ptr_got;
	int		actual_line[2];

	if (!print || open_files(file_exp, file_got, &ptr_exp, &ptr_got))
		return (FAILURE);
	temp = *line_lst;
	printf("\nDiff exp-%s got-%s\n", file_exp, file_got);
	printf("--- exp-%s\n+++ got-%s\n", file_exp, file_got);
	actual_line[0] = 1;
	actual_line[1] = 1;
	while (temp)
	{
		printf("Line %d:\n", temp->line_no);
		print_line(temp->line_no, &(actual_line[0]), ptr_exp, 1);
		print_line(temp->line_no, &(actual_line[1]), ptr_got, 0);
		prev = temp;
		temp = temp->next;
		free(prev);
	}
	close_files(ptr_exp, ptr_got);
	return (FAILURE);
}

static void	move_file_pointer(FILE *file, char *letter)
{
	while (*letter != EOF && *letter != '\n')
		*letter = fgetc(file);
}

static void	place_at_line_start(FILE *ptr_exp, FILE *ptr_got, char *exp, char *got)
{
	char	*letter;
	FILE	*file;

	if (*exp == *got)
		return ;
	if (*exp == '\n')
	{
		letter = got;
		file = ptr_got;
	}
	else
	{
		letter = exp;
		file = ptr_exp;
	}
	move_file_pointer(file, letter);
}

int	file_diff(char *file_exp, char *file_got, int print)
{
	FILE	*ptr_exp;
	FILE	*ptr_got;
	char	comp[2] = "12";
	t_line	*line_lst = NULL;
	int		line_no = 1;

	if (open_files(file_exp, file_got, &ptr_exp, &ptr_got))
		return (1);
	while (comp[0] != EOF && comp[1] != EOF)
	{
		comp[0] = fgetc(ptr_exp);
		comp[1] = fgetc(ptr_got);
		if (comp[0] != comp[1])
		{
			if (!print)
				return (close_files(ptr_exp, ptr_got));
			add_line(&line_lst, line_no);
		}
		if (comp[0] == '\n' || comp[1] == '\n')
		{
			place_at_line_start(ptr_exp, ptr_got, &comp[0], &comp[1]);
			line_no++;
		}
	}
	close_files(ptr_exp, ptr_got);
	if (comp[0] == EOF && comp[1] == EOF && !line_lst)
		return (SUCCESS);
	return (print_diff(&line_lst, file_exp, file_got, print));
}
