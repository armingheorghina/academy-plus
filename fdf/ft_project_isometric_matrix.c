/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_project_isometric_matrix.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:40:40 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/02 17:56:26 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**ft_project_isometric_matrix(t_env *m)
{
	t_point	**matrix;
	int		i;
	int		j;

	matrix = (t_point**)malloc(sizeof(*matrix) * m->rows);
	i = 0;
	while (i < m->rows)
	{
		matrix[i] = (t_point*)malloc(sizeof(t_point) * m->columns);
		j = 0;
		while (j < m->columns)
		{
			matrix[i][j].x = WIDTH / 2 + m->map2[i][j].x * m->spacing *
				cos(DEG30) - m->map2[i][j].y * m->spacing * cos(DEG30);
			matrix[i][j].y = HEIGHT / 2 + m->map2[i][j].x * m->spacing *
				sin(DEG30) + m->map2[i][j].y * m->spacing * sin(DEG30) -
				m->map2[i][j].z * m->spacing;
			matrix[i][j].z = m->map2[i][j].z;
			j++;
		}
		i++;
	}
	return (matrix);
}
