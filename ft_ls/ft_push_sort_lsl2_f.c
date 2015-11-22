#include "ft_ls.h"

void	ft_push_sort_lsl2_f(t_ls_list_f *start, char *str, off_t st_size, time_t time)
{
	while (start)
	{
		if (ft_strcmp(str, start->name) == 0)
		{
			start->bytes_size = st_size;
			start->mtime = time;
		}
		start = start->next;
	}
}
