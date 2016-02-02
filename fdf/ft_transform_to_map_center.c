/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_to_map_center.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:03:08 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/02 17:27:31 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_transform_all_points_relative_to_map_center(t_env *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			(m->map2)[i][j].x -= (m->columns / 2);
			(m->map2)[i][j].y -= (m->rows / 2);
			j++;
		}
		i++;
	}
}
