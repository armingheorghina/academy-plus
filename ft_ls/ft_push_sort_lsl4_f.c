#include "ft_ls.h"

void	ft_push_sort_lsl4_f(t_ls_list_f *start, char *str, nlink_t st_nlink, mode_t st_mode)
{
	while (start)
	{
		if (ft_strcmp(str, start->name) == 0)
		{
			start->nlink = st_nlink;
			start->mode = st_mode;
		}
		start = start->next;
	}
}
