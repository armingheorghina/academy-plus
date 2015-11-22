#include "ft_ls.h"

void	ft_push_sort_lsl3_f(t_ls_list_f *start, char *str, uid_t st_uid, gid_t st_gid)
{
	while (start)
	{
		if (ft_strcmp(str, start->name) == 0)
		{
			start->uid = st_uid;
			start->gid = st_gid;
		}
		start = start->next;
	}
}

