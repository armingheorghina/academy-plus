/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:44:54 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/02 17:36:16 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_cant_open_file(char *filename)
{
	perror(filename);
	exit(0);
}

char	**ft_get_cmap(char *filename, t_env *m)
{
	int		fd;
	char	*line;
	char	**map;
	int		ok;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_cant_open_file(filename);
	ok = 0;
	while (ft_get_next_line(fd, &line))
		ok++;
	m->rows = ok;
	close(fd);
	map = (char**)malloc(sizeof(*map) * (ok + 1));
	fd = open(filename, O_RDONLY);
	i = 0;
	while (ft_get_next_line(fd, &line))
	{
		map[i] = line;
		i++;
	}
	map[i] = 0;
	return (map);
}
