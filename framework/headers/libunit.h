#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <sys/time.h>
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

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

typedef struct s_unit_lst
{
	char *describe;
	int (*test)(void);
	struct s_unit_lst *next;
}	t_unit_lst;

void	clean_tests(t_unit_lst **lst);
int		launch_tests(t_unit_lst **lst);
void	load_test(t_unit_lst **lst, char *describe, int (*test)(void));
#endif
