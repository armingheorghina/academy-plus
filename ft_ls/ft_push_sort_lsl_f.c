#include "ft_ls.h"

void	ft_push_sort_lsl_f(t_ls_list_f **begin, char *str, blkcnt_t st_blocks, char *lbuf)
{
	t_ls_list_f *new;
	t_ls_list_f *list;
	int ok;

	new = (t_ls_list_f*)malloc(sizeof(t_ls_list_f));
	new->name = ft_strdup(str);
	new->blocks = st_blocks;
	new->link_name = lbuf;
	list = *begin;
	new->next = NULL;
	if (list == NULL)
		*begin = new;
	else
	{
		if (ft_strcmp(list->name, new->name) > 0)
		{
			new->next = *begin;
			*begin = new;
		}
		else
		{
			ok = 1;
			while (list->next && ok)
			{
				if (ft_strcmp((list->next)->name, new->name) > 0)
				{
					new->next = list->next;
					list->next = new;
					ok = 0;
				}
				list = list->next;
			}
			if (ok == 1)
				list->next = new;			
		}
	}
}
