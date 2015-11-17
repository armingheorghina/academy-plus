/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 23:26:11 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/17 12:02:52 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_push_sort_lsl(t_ls_list **begin, char *str, off_t size, time_t time, uid_t st_uid, gid_t st_gid, nlink_t st_nlink, mode_t st_mode, blkcnt_t st_blocks, char *lbuf)
{
	t_ls_list *new;
	t_ls_list *list;
	int ok;

	new = (t_ls_list*)malloc(sizeof(t_ls_list));
	new->name = ft_strdup(str);
	new->bytes_size = size;
	new->mtime = time;
	new->uid = st_uid;
	new->gid = st_gid;
	new->nlink = st_nlink;
	new->mode = st_mode;
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
		a = ft_strlen(pwd->pw_name);
		if (a > b)
			b = a;
		grp = getgrgid(start->gid);
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

void	ft_putuid_name(struct passwd *pwd, int biggest_uid_len)
{
	unsigned long i;

	i = 0;
	ft_putstr(pwd->pw_name);
	while (i < biggest_uid_len - ft_strlen(pwd->pw_name))
	{
		write(1, " ", 1);
		i++;
	}
	ft_putchar(' ');
	ft_putchar(' ');
}

void	ft_putgid_name(struct group *grp, int biggest_gid_len)
{
	unsigned long i;

	i = 0;
	ft_putstr(grp->gr_name);
	while (i < biggest_gid_len - ft_strlen(grp->gr_name))
	{
		write(1, " ", 1);
		i++;
	}
	ft_putchar(' ');
	ft_putchar(' ');
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

void	ft_putmode(mode_t mode)
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

void	ft_putlist_lsl(t_ls_list *start)
{

	ft_put_total(start);
	while (start)
	{
		ft_putmode(start->mode);
		ft_puthardlinks((int)start->nlink, start->biggest_nlink_len);
		ft_putuid_name(getpwuid(start->uid), start->biggest_uid_len);
		ft_putgid_name(getgrgid(start->gid), start->biggest_gid_len);
		ft_putbytes((int)start->bytes_size, start->biggest_size_len);
		ft_puttime(ctime(&(start->mtime)));
		if (S_ISLNK(start->mode) == 1) /* if file is a link*/
			ft_putlink(start->name, start->link_name);
		else
			ft_putendl(start->name);
		start = start->next;
	}
}

void	ft_delete_hidden_from_list(t_ls_list **start)
{
	t_ls_list *start2;

	start2 = *start;
	while (start2)
	{
		if (ft_ishidden(start2->name))
		{
			*start = start2->next;
			free(start2);
		}
		start2 = start2->next;
	}
}

int		ft_isflag(int i, char *flag, char **argv)
{
	if (ft_strcmp(argv[i], flag) == 0)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				close_dir;
	int				i;
	t_ls_list		*start;
	struct stat		*buf;
	char			*lbuf = NULL;
	//int			stat_return;

	i = 1;
	while (i < argc) // *TODO add multiple flags functionality
	{
		if (ft_isflag(i, "-l", argv) == 1 && i < 2)
		{
			i++;
			if (argv[i] == NULL) // flag only.
			argv[i] = ".";
		}

		while (ft_isflag(i, "-l", argv) == 1 && i >= 2 && i < argc - 1)
			i++;
		if (ft_isflag(i, "-l", argv) == 1 && i >= 2 && i == argc - 1)
			return (0);
		dirp = opendir(argv[i]);
		if (dirp != NULL)
		{
			start = NULL;
			while ((dp = readdir(dirp)) != NULL)
			{
				buf = (struct stat*)malloc(sizeof(*buf));
				(void)lstat(ft_strjoin(ft_strjoin(argv[i], "/"), dp->d_name), buf);
				lbuf = (char*)malloc(buf->st_size);
				(void)readlink(ft_strjoin(ft_strjoin(argv[i], "/"), dp->d_name), lbuf, buf->st_size);
				ft_push_sort_lsl(&start, dp->d_name, buf->st_size, buf->st_mtime, buf->st_uid, buf->st_gid, buf->st_nlink, buf->st_mode, buf->st_blocks, lbuf);
				if (dp == NULL) // *TODO move this 2 lines to top of while in all files
					perror("readdir error");
			}
			if (argc > 3)
			{
				ft_putstr(argv[i]);
				ft_putstr(":\n");
			}
			ft_delete_hidden_from_list(&start);
			ft_push_bsl_bnl_to_list(start);
			ft_push_buidl_bgidl_to_list(start);
			ft_putlist_lsl(start);
			// *TODO free list : use ft_lstdel(start, f_free_str)
			if (argc > 3 && i != argc - 1) // && ft_isflag(argc - 1, "-a", argv))
				ft_putchar('\n');
			close_dir = closedir(dirp);
			if (close_dir == -1)
				perror("closedir error");
		}
		else if (dirp == NULL)
		{
			ft_putstr(argv[0]);
			ft_putstr(": ");
			perror(argv[i]);
		}
		i++;
	}
	return (0);
}
