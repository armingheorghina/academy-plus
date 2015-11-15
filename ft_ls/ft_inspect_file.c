/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 23:26:11 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/14 01:34:06 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_push_sort_lsa(t_ls_list **begin, char *str, off_t size, time_t time)
{
	t_ls_list *new;
	t_ls_list *list;
	int ok;

	new = (t_ls_list*)malloc(sizeof(t_ls_list));
	new->name = ft_strdup(str);
	new->bytes_size = size;
	new->mtime = time;
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

void	ft_push_biggest_size_len_to_list(t_ls_list *start)
{
	int		x;
	int		y;
	t_ls_list	*start2;

	x = 0;
	y = 0;
	start2 = start;
	while (start)
	{
		x = ft_strlen(ft_itoa((int)start->bytes_size)); //*TODO use a smarter way to count this.
		if (x > y)
			y = x;
		start = start->next;
	}
	while (start2)
	{
		start2->biggest_size_len = y;
		start2 = start2->next;
	}
}

void	ft_putbytes(int bytes_size, int biggest_size_len)
{
	int x;

	x = ft_strlen(ft_itoa(bytes_size)); //*TODO use a smarter way to count this.
	write(1, "                                          ", biggest_size_len - x);
	ft_putnbr(bytes_size);
	write(1, " ", 1);
}

void	ft_putlist_lsa(t_ls_list *start)
{
	while (start)
	{
		if (!ft_ishidden(start->name))		
		{
			ft_putbytes((int)start->bytes_size, start->biggest_size_len);
			ft_puttime(ctime(&start->mtime));
			ft_putendl(start->name);
		}
		start = start->next;
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
	DIR			*dirp;
	struct dirent		*dp;
	int			close_dir;
	int			i;
	t_ls_list		*start;
	struct stat		*buf;
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
				(void)stat(dp->d_name, buf);
				ft_push_sort_lsa(&start, dp->d_name, buf->st_size, buf->st_mtime);
				if (dp == NULL) // *TODO move this 2 lines to top of while in all files
					perror("readdir error");
			}
			if (argc > 3)
			{
				ft_putstr(argv[i]);
				ft_putstr(":\n");
			}
			ft_push_biggest_size_len_to_list(start);
			ft_putlist_lsa(start);
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
