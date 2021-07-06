#include "libunit.h"

void	clean_tests(t_unit_lst **lst)
{
	t_unit_lst	*temp;
	t_unit_lst	*my_lst;

	if (!lst)
		return ;
	my_lst = *lst;
	if (!my_lst)
	{
		lst = NULL;
		return ;
	}
	while (my_lst)
	{
		temp = my_lst->next;
		free(my_lst);
		my_lst = temp;
	}
	*lst = NULL;
}

void clean_suites(t_suite_lst **lst)
{
	t_suite_lst *temp;
	t_suite_lst *to_free;

	to_free = *lst;
	while (to_free)
	{
		temp = to_free->next;
		free(to_free);
		to_free = temp;
	}
}
