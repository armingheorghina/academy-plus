#include "ft_ls.h"

void	ft_push_buidl_bgidl_to_list_f(t_ls_list_f *start)
{
	int				a;
	int 			b;
	struct passwd	*pwd;
	int				c;
	int				d;
	struct group	*grp;
	t_ls_list_f		*start2;

	a = 0;
	b = 0;
	c = 0;
	d = 0;
	start2 = start;
	while (start)
	{
		pwd = getpwuid(start->uid);
		if (pwd == NULL)
			a = ft_strlen(ft_itoa((int)start->uid));
		else
			a = ft_strlen(pwd->pw_name);
		if (a > b)
			b = a;
		grp = getgrgid(start->gid);
		if (grp == NULL)
			c = ft_strlen(ft_itoa((int)start->gid));
		else
			c = ft_strlen(grp->gr_name);
		if (c > d)
			d = c;
		start = start->next;
	}
	while (start2)
	{
		start2->biggest_uid_len = b;
		start2->biggest_gid_len = d;
		start2 = start2->next;
	}
}
