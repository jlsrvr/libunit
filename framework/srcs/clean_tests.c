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
