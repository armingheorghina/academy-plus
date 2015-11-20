/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 23:26:11 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/20 13:00:27 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_push_sort_lsl(t_ls_list **begin, char *str, blkcnt_t st_blocks, char *lbuf)
{
	t_ls_list *new;
	t_ls_list *list;
	int ok;

	new = (t_ls_list*)malloc(sizeof(t_ls_list));
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


void	ft_push_sort_lsl0(t_ls_list **begin, char *str, blkcnt_t st_blocks, char *lbuf)
{
	t_ls_list *new;
	t_ls_list *list;
	t_ls_list *p;
	t_ls_list *timep;

	new = (t_ls_list*)malloc(sizeof(t_ls_list));
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
	timep = *begin;
	while (timep)

//	while (*begin)
//	{
//
//		*begin = *begin->next
//	}
}







void	ft_push_sort_lsl2(t_ls_list *start, char *str, off_t st_size, time_t time)
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

void	ft_push_sort_lsl3(t_ls_list *start, char *str, uid_t st_uid, gid_t st_gid)
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

void	ft_push_sort_lsl4(t_ls_list *start, char *str, nlink_t st_nlink, mode_t st_mode)
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

void	ft_push_sort_lsl5(t_ls_list *start, char *str, ssize_t xattr)
{
	while (start)
	{
		if (ft_strcmp(str, start->name) == 0)
			start->xattr_nbr = xattr;
		start = start->next;
	}
}

void	ft_puttime(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i >= 4 && i <= 15)
			write(1, &str[i], 1);
		i++;
	}
	write(1, " ", 1);
}

int             ft_ishidden(char *str)
{
        if (str[0] == '.')
                return (1);
        return (0);
}

void	ft_push_bsl_bnl_to_list(t_ls_list *start)
{
	int			a;
	int			b;
	int			c;
	int			d;
	t_ls_list	*start2;

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

void	ft_push_buidl_bgidl_to_list(t_ls_list *start)
{
	int				a;
	int 			b;
	struct passwd	*pwd;
	int				c;
	int				d;
	struct group	*grp;
	t_ls_list		*start2;

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

void	ft_putbytes(int bytes_size, int biggest_size_len)
{
	int x;
	int i;

	x = ft_strlen(ft_itoa(bytes_size)); //*TODO use a smarter way to count this.
	i = 0;
	while (i < biggest_size_len - x)
	{
		write(1, " ", 1);
		i++;
	}
	ft_putnbr(bytes_size);
	write(1, " ", 1);
}

void	ft_putuid_name(uid_t name, int biggest_uid_len)
{
	unsigned long i;
 	struct passwd *pwd;
	
	i = 0;
	pwd = getpwuid(name);
	if (pwd == NULL)
	{
		ft_putstr(ft_itoa((int)name));
		while (i < biggest_uid_len - ft_strlen(ft_itoa((int)name)))
		{
			write(1, " ", 1);
			i++;
		}
		ft_putchar(' ');
		ft_putchar(' ');
	}
	else
	{
		ft_putstr(pwd->pw_name);
		while (i < biggest_uid_len - ft_strlen(pwd->pw_name))
		{
			write(1, " ", 1);
			i++;
		}
		ft_putchar(' ');
		ft_putchar(' ');
	}
}

void	ft_putgid_name(gid_t name, int biggest_gid_len)
{
	unsigned long i;
	struct group *grp;

	i = 0;
	grp = getgrgid(name);
	if (grp == NULL)
	{
		ft_putstr(ft_itoa((int)name));
		while (i < biggest_gid_len - ft_strlen(ft_itoa((int)name)))
		{
			write(1, " ", 1);
			i++;
		}
		ft_putchar(' ');
		ft_putchar(' ');
	}
	else
	{
		ft_putstr(grp->gr_name);
		while (i < biggest_gid_len - ft_strlen(grp->gr_name))
		{
			write(1, " ", 1);
			i++;
		}
		ft_putchar(' ');
		ft_putchar(' ');
	}
}

void	ft_puthardlinks(int nlink, int biggest_nlink_len)
{
	int x;
	int i;

	x = ft_strlen(ft_itoa(nlink));
	i = 0;
	while (i < biggest_nlink_len - x)
	{
		write(1, " ", 1);
		i++;
	}
	ft_putnbr(nlink);
	ft_putchar(' ');
}

void	ft_putmode(mode_t mode, ssize_t xattr_nbr)
{
	
	if (S_ISREG(mode) == 1)
		ft_putchar('-');
	if (S_ISDIR(mode) == 1)
		ft_putchar('d');
	if (S_ISCHR(mode) == 1)
		ft_putchar('c');
	if (S_ISBLK(mode) == 1)
		ft_putchar('b');
	if (S_ISFIFO(mode) == 1)
		ft_putchar('f');
	if (S_ISLNK(mode) == 1)
		ft_putchar('l');
	if (S_ISSOCK(mode) == 1)
		ft_putchar('s');
	if (mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
   	if (mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
   	if (mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
   	if (mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
   	if (mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
   	if (mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
   	if (mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
   	if (mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
	if (xattr_nbr > 0)
		ft_putchar('@');
	else
		ft_putchar(' ');
	ft_putchar(' ');
}

void		ft_put_total(t_ls_list *start)
{
	int x;

	x = 0;
	while (start)
	{
		x = (int)start->blocks + x;
		start = start->next;
	}
	ft_putstr("total ");
	ft_putnbr(x);
	ft_putchar('\n');
}

void	ft_putlink(char	*file_name, char *link_name)
{
	ft_putstr(file_name);
	ft_putstr(" -> ");
	ft_putstr(link_name);
	ft_putchar('\n');
}

void	ft_putlist_lsl(t_ls_list *start, char *flag)
{
	if (ft_check_if_flag_contains(flag, 'l') == 1)
		ft_put_total(start);
	while (start)
	{
		
		if (ft_check_if_flag_contains(flag, 'l') == 1)
		{
			ft_putmode(start->mode, start->xattr_nbr);
			ft_puthardlinks((int)start->nlink, start->biggest_nlink_len);
		//	ft_putuid_name(getpwuid(start->uid), start->biggest_uid_len);
			ft_putuid_name(start->uid, start->biggest_uid_len);
	//		ft_putgid_name(getgrgid(start->gid), start->biggest_gid_len);
			ft_putgid_name(start->gid, start->biggest_gid_len);
			ft_putbytes((int)start->bytes_size, start->biggest_size_len);
			ft_puttime(ctime(&(start->mtime)));
			if (S_ISLNK(start->mode) == 1) /* special case for links listing*/
				ft_putlink(start->name, start->link_name);
			else
				ft_putendl(start->name);
		}
		else
			ft_putendl(start->name);
		start = start->next;
	}
}

void	ft_delete_hidden_from_list(t_ls_list **start)
{
	t_ls_list *curr;
	t_ls_list *prev;

	curr = *start;
	prev = NULL;
	while (curr)
	{
		if (ft_ishidden(curr->name))
		{
			if (prev == NULL)
				*start = curr->next;
			else
				prev->next = curr->next;
			free(curr);
		}
		else
			prev = curr;
		curr = curr->next;
	}
}

int		ft_isflag(int i, char *flag, char **argv)
{
	if (ft_strcmp(argv[i], flag) == 0)
		return (1);
	return (0);
}

char	ft_get_file_type(int i, char **argv)
{
	struct stat		*buf;
	
	buf = (struct stat*)malloc(sizeof(*buf));
	(void)lstat((argv[i]), buf);
	if (S_ISDIR(buf->st_mode) == 1)
		return ('d');
	if (S_ISREG(buf->st_mode) == 1)
		return ('-');
	if (S_ISCHR(buf->st_mode) == 1)
		return ('c');
	if (S_ISBLK(buf->st_mode) == 1)
		return ('b');
	if (S_ISFIFO(buf->st_mode) == 1)
		return ('f');
	if (S_ISLNK(buf->st_mode) == 1)
		return ('l');
	if (S_ISSOCK(buf->st_mode) == 1)
		return ('s');
	else
		return ('e');
}

char	*ft_get_flag(int i, int argc, char **argv)
{
	char	*flag;

	flag = ft_strdup("");
	while (i < argc && argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
	{
		flag = ft_strjoin(flag, argv[i] + 1);
		i++;
	}
	return (flag);
}

int		ft_get_flags_number(int i, int argc, char** argv)
{
	int flags_number;

	flags_number = 0;
	while (i < argc && argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
	{
		flags_number++;
		i++;
	}
	return (flags_number);
}

void	ft_strswap(char **str1, char **str2)
{
	char *temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	ft_modeswap(mode_t *mode1, mode_t *mode2)
{
	mode_t temp;

	temp = *mode1;
	*mode1 = *mode2;
	*mode2 = temp;
}

void	ft_nlinkswap(nlink_t *nlink1, nlink_t *nlink2)
{
	nlink_t	temp;
	
	temp = *nlink1;
	*nlink1 = *nlink2;
	*nlink2 = temp;
}

void	ft_intswap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_uid_tswap(uid_t *uid1, uid_t *uid2)
{
	uid_t temp;

	temp = *uid1;
	*uid1 = *uid2;
	*uid2 = temp;
}

void	ft_gid_tswap(gid_t *gid1, gid_t *gid2)
{
	gid_t temp;

	temp = *gid1;
	*gid1 = *gid2;
	*gid2 = temp;
}

void	ft_off_tswap(off_t *bytes_size1, off_t *bytes_size2)
{
	off_t temp;

	temp = *bytes_size1;
	*bytes_size1 = *bytes_size2;
	*bytes_size2 = temp;
}

void	ft_blkcnt_tswap(blkcnt_t *blocks1, blkcnt_t *blocks2)
{
	blkcnt_t temp;

	temp = *blocks1;
	*blocks1 = *blocks2;
	*blocks2 = temp;
}

void	ft_time_tswap(time_t *time1, time_t *time2)
{
	time_t temp;

	temp = *time1;
	*time1 = *time2;
	*time2 = temp;
}

void	ft_ssize_tswap(ssize_t *a, ssize_t *b)
{
	ssize_t temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_list_reverse(t_ls_list *start, char *flag)
{
	t_ls_list *start2;

	while (start)
	{
		start2 = start->next;
		while (start2)
		{
			if ((start->mtime > start2->mtime) && ft_check_if_flag_contains(flag, 't') == 1)
			{
				ft_strswap(&(start->name), &(start2->name));
				ft_modeswap(&(start->mode), &(start2->mode));
				ft_nlinkswap(&(start->nlink), &(start2->nlink));
				ft_uid_tswap(&(start->uid), &(start2->uid));
				ft_gid_tswap(&(start->gid), &(start2->gid));
				ft_off_tswap(&(start->bytes_size), &(start2->bytes_size));
				ft_blkcnt_tswap(&(start->blocks), &(start2->blocks));
				ft_time_tswap(&(start->mtime), &(start2->mtime));
				ft_strswap(&(start->link_name), &(start2->link_name));
				ft_ssize_tswap(&(start->xattr_nbr), &(start2->xattr_nbr));
			}
			else if	(ft_strcmp(start->name, (start2)->name) < 0)
			{
				ft_strswap(&(start->name), &(start2->name));
				ft_modeswap(&(start->mode), &(start2->mode));
				ft_nlinkswap(&(start->nlink), &(start2->nlink));
				ft_uid_tswap(&(start->uid), &(start2->uid));
				ft_gid_tswap(&(start->gid), &(start2->gid));
				ft_off_tswap(&(start->bytes_size), &(start2->bytes_size));
				ft_blkcnt_tswap(&(start->blocks), &(start2->blocks));
				ft_time_tswap(&(start->mtime), &(start2->mtime));
				ft_strswap(&(start->link_name), &(start2->link_name));
				ft_ssize_tswap(&(start->xattr_nbr), &(start2->xattr_nbr));
			}

			start2 = start2->next;
		}
		start = start->next;
	}
}
void	ft_sort_list_by_mtime(t_ls_list *start)
{
	t_ls_list *start2;

	while (start)
	{
		start2 = start->next;
		while (start2)
		{
			if (start->mtime < start2->mtime)
			{
				ft_strswap(&(start->name), &(start2->name));
				ft_modeswap(&(start->mode), &(start2->mode));
				ft_nlinkswap(&(start->nlink), &(start2->nlink));
				ft_uid_tswap(&(start->uid), &(start2->uid));
				ft_gid_tswap(&(start->gid), &(start2->gid));
				ft_off_tswap(&(start->bytes_size), &(start2->bytes_size));
				ft_blkcnt_tswap(&(start->blocks), &(start2->blocks));
				ft_time_tswap(&(start->mtime), &(start2->mtime));
				ft_strswap(&(start->link_name), &(start2->link_name));
				ft_ssize_tswap(&(start->xattr_nbr), &(start2->xattr_nbr));
			}
			start2 = start2->next;
		}
		start = start->next;
	}
}
int		main(int argc, char **argv)
{
	int	i;
	char	*flag;
	int	flags_number;

	i = 1;
	flag = ft_get_flag(i, argc, argv);
	flags_number = ft_get_flags_number(i, argc, argv);
	i = i + flags_number;
	if (argv[i] == NULL && i == argc) // flags only.
	{
		argv[i] = ".";
		ft_work_with_d(i, argc, argv, flag);
	}
	while (i < argc) // *TODO add multiple flags functionality
	{
		ft_work_with_e(i, argv);
		ft_work_with_d(i, argc, argv, flag);
		i++;
	}
	return (0);
}
/*
a -delete sau nu hidden;
sortare - daca nu aapare t si u ... sortez dupa nume
l - long listing;
delete ft_isflag - nu se foloseste si oricum e gresita
*/
