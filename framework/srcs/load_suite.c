#include "libunit.h"

static t_suite_lst	*new_suite(int (*func)(void))
{
	t_suite_lst	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		return (NULL);
	elem->suite = func;
	elem->next = NULL;
	return (elem);
}

static void	add_suite_to_end(t_suite_lst **lst, t_suite_lst *new)
{
	t_suite_lst	*temp;

	temp = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	load_suite(t_suite_lst **lst, int (*suite)(void))
{
	t_suite_lst	*new;

	new = new_suite(suite);
	if (!new)
		return ;
	add_suite_to_end(lst, new);
}
