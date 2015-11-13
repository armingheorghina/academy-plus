/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 16:41:04 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/13 20:01:26 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_push_sort_lsa(t_ls_list **begin, char *str)
{
	t_ls_list *new;
	t_ls_list *list;
	int ok;

	new = (t_ls_list*)malloc(sizeof(t_ls_list));
	new->name = ft_strdup(str);
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

void	ft_putlist_lsa(t_ls_list *start)
{
	while (start)
	{
		ft_putendl(start->name);
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
	DIR				*dirp;
	struct dirent	*dp;
	int				close_dir;
	int				i;
	t_ls_list			*start;


	i = 1;
	while (i < argc) // *TODO add multiple flags functionality
	{
		if (ft_isflag(i, "-a", argv) == 1 && i < 2)
		{
			i++;
			if (argv[i] == NULL) // flag only.
			argv[i] = ".";
		}
		while (ft_isflag(i, "-a", argv) == 1 && i >= 2 && i < argc - 1)
			i++;
		if (ft_isflag(i, "-a", argv) == 1 && i >= 2 && i == argc - 1)
			return (0);
		dirp = opendir(argv[i]);
		if (dirp != NULL)
		{
			start = NULL;
			while ((dp = readdir(dirp)) != NULL)
			{
				ft_push_sort_lsa(&start, dp->d_name);
				if (dp == NULL)
					perror("readdir error");
			}
			if (argc > 3)
			{
				ft_putstr(argv[i]);
				ft_putstr(":\n");
			}
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
