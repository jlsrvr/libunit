#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <sys/time.h>
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "get_next_line.h"

# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define PINK	"\e[35m"
# define CYAN	"\e[36m"
# define BOLD	"\e[1m"
# define UNDER	"\e[4m"
# define BLINK	"\e[5m"
# define RESET  "\e[0m"

# define DISPLAY_SIZE 30
# define TIME_LIMIT 2
# define SUCCESS 0
# define FAILURE 1
# define UNKNOWN 0x42000000
# define FORK 0x42000001

typedef struct s_line
{
	int line_no;
	struct s_line *next;
}	t_line;

typedef struct s_fd
{
	int file_fd;
	int copy_og;
	FILE *og_output;
}	t_fd;

typedef struct s_unit_lst
{
	char				*describe;
	int					(*test)(void*);
	void				*params;
	struct s_unit_lst	*next;
}	t_unit_lst;

typedef struct s_suite_lst
{
	int					(*suite)(void);
	struct s_suite_lst	*next;
}	t_suite_lst;

void    add_test_to_end(t_unit_lst **lst, t_unit_lst *new);
void	clean_tests(t_unit_lst **lst);
int		launch_tests(t_unit_lst **lst, char *title);
void	load_test(t_unit_lst **lst, char *describe, int (*test)(void*), void *params);
void	load_suite(t_suite_lst **lst, int (*suite)(void));
int		run_suites(t_suite_lst **suites, char *title);

t_fd    *redirect_stdout(char *filepath);
t_fd    *redirect_stderr(char *filepath);
void	reverse_redirect(t_fd *my_fd);

int		file_diff(char *filepath1, char *filepath2, int print);
#endif
