#include "ft_ls.h"

void	ft_push_sort_lsl5_f(t_ls_list_f *start, char *str, ssize_t xattr, time_t time)
{
	while (start)
	{
		if (ft_strcmp(str, start->name) == 0)
		{
			start->xattr_nbr = xattr;
			start->atime = time;
		}
		start = start->next;
	}
}
