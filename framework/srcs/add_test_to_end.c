#include "libunit.h"

void	add_test_to_end(t_unit_lst **lst, t_unit_lst *new)
{
	t_unit_lst	*temp;

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
