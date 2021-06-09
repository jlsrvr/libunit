#include "libunit.h"

static t_unit_lst	*new_test(char *describe, int (*func)(void*), void *params)
{
	t_unit_lst	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		return (NULL);
	elem->describe = describe;
	elem->test = func;
	elem->params = params;
	elem->next = NULL;
	return (elem);
}

void	load_test(t_unit_lst **lst, char *describe, int (*test)(void*), void *params)
{
	t_unit_lst	*new;

	new = new_test(describe, test, params);
	if (!new)
		return ;
	add_test_to_end(lst, new);
}
