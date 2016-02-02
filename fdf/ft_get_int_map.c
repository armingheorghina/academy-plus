/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:46:05 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/02 17:44:29 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_first_row_columns_number(char *str)
{
	char	**temp_map;
	int		j;

	temp_map = ft_strsplit(str, ' ');
	j = 0;
	while (temp_map[j])
		j++;
	return (j);
}

int		**ft_get_int_map(char **cmap, t_env *m)
{
	int		i;
	int		j;
	int		**map;
	char	**temp_map;

	map = (int**)malloc(sizeof(int*) * m->rows);
	m->columns = ft_get_first_row_columns_number(cmap[0]);
	i = 0;
	while (cmap[i])
	{
		map[i] = (int*)malloc(sizeof(int) * m->columns);
		temp_map = ft_strsplit(cmap[i], ' ');
		j = 0;
		while (temp_map[j])
		{
			map[i][j] = ft_atoi(temp_map[j]);
			j++;
		}
		free(temp_map);
		if (j != m->columns)
			ft_error_and_exit();
		i++;
	}
	return (map);
}
