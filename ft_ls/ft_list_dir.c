/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 18:16:49 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/11 21:07:05 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				close_dir;
	int				i;

	i = 1;
	while (i < argc)
	{
		dirp = opendir(argv[i]);
		if (dirp == NULL)
		{
			ft_putstr(argv[0]);
			ft_putchar(':');
			ft_putchar(' ');
			perror(argv[i]);
		}
		else
		{
			while ((dp = readdir(dirp)) != NULL)
			{
				ft_putendl(dp->d_name);
			}
			close_dir = closedir(dirp);
			if (close_dir == -1)
				perror("no close");
		}

		i++;
	}
	return (0);
}
