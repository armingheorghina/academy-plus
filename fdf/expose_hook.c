/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:43:53 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/02 17:31:47 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *m)
{
	int		i;
	int		j;
	t_point	**matrix;

	matrix = ft_project_isometric_matrix(m);
	m->zmin = ft_get_zmin(matrix, m);
	m->zmax = ft_get_zmax(matrix, m);
	mlx_clear_window(m->mlx, m->win);
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			mlx_pixel_put(m->mlx, m->win, matrix[i][j].x, matrix[i][j].y,
					ft_color(m, matrix[i][j]));
			j++;
		}
		i++;
	}
	ft_draw_lines_between_points(matrix, m);
	ft_show_usage(m);
	return (0);
}
