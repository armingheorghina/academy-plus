/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 18:16:49 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/12 16:06:48 by vdruta           ###   ########.fr       */
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
		if (ft_strcmp(argv[i], "-a") == 0)
			i++;
		if (argv[i] == NULL) //if nothing is givven after flag;
			argv[i] = ".";
		dirp = opendir(argv[i]);
		if (dirp != NULL)
		{
			while ((dp = readdir(dirp)) != NULL)
			{
				ft_putendl(dp->d_name);
				if (dp == NULL)
					perror("readdir error");
			}
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
