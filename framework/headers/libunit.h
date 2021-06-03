#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <sys/time.h>
# include <signal.h>
# include <sys/wait.h>

typedef struct s_unit_lst
{
	char *describe;
	int (*func)(void);
	struct s_unit_lst *next;
}	t_unit_lst;

void	load_test(t_unit_lst **lst, char *describe, int (*test)(void));
#endif
