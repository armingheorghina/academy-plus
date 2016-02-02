/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_initial_coordinates.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:47:55 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/02 16:48:08 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**ft_generate_initial_coordinates(t_env *m)
{
	t_point **temp;
	int		i;
	int		j;

	temp = (t_point**)malloc(sizeof(*temp) * (m->rows));
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		temp[i] = (t_point*)malloc(sizeof(t_point) * m->columns);
		while (j < m->columns)
		{
			temp[i][j].x = j;
			temp[i][j].y = i;
			temp[i][j].z = m->map[i][j];
			j++;
		}
		i++;
	}
	return (temp);
}
