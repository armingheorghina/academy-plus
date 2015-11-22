#include "ft_ls.h"

void	ft_push_bsl_bnl_to_list_f(t_ls_list_f *start)
{
	int			a;
	int			b;
	int			c;
	int			d;
	t_ls_list_f	*start2;

	a = 0;
	b = 0;
	c = 0;
	d = 0;
	start2 = start;
	while (start)
	{
		c = ft_strlen(ft_itoa((int)start->bytes_size)); //*TODO do it smarter.
		if (c > d)
			d = c;
		a = ft_strlen(ft_itoa((int)start->nlink)); //*TODO do it smarter.
		if (a > b)
			b = a;
		start = start->next;
	}
	while (start2)
	{
		start2->biggest_size_len = d;
		start2->biggest_nlink_len = b;
		start2 = start2->next;
	}
}
