#include "ft_ls.h"

void	ft_push_sort_lsl0_f(t_ls_list_f **begin, char *str, blkcnt_t st_blocks, char *lbuf)
{
	t_ls_list_f *new;
	t_ls_list_f *list;
	t_ls_list_f *p;

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
		p = *begin;
		while (p->next)
			p = p->next;
		p->next = new;
	}
}
