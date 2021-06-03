#include "libunit.h"

static t_unit_lst	*new_test(char *describe, int (*func)(void))
{
	t_unit_lst *elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		return (NULL);
	elem->describe = describe;
	elem->test = func;
	elem->next = NULL;
	return (elem);
}

static void add_test_to_end(t_unit_lst **lst, t_unit_lst *new)
{
	t_unit_lst *temp;

	temp = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp_next;
	temp->next = new;
}

void	load_test(t_unit_lst **lst, char *describe, int (*test)(void))
{
	t_unit_lst *new;

	new = new_test(describe, test);
	if (!new)
		return ;
	add_test_to_end(lst, new);
}
