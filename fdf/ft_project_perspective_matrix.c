/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_project_perspective_matrix.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:58:01 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/04 17:15:05 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_45(t_point *point, float radians)
{
	float		c;
	float		s;
	float		xp;
	float		yp;

	c = cos(radians);
	s = sin(radians);
	xp = point->y * c - point->z * s;
	yp = point->y * s + point->z * c;
	point->y = xp;
	point->z = yp;
}

int		ft_give_me_a_number(void)
{
	static int i = 0;

	i++;
	return (i);
}

t_point	**ft_project_perspective_matrix(t_env *m)
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
			if (ft_give_me_a_number() <= m->rows * m->columns)
				ft_rotate_45(&m->map3[i][j], 0.785);
				//m->map3[i][j].z += m->rows / 2 + i;
			matrix[i][j].x = WIDTH / 2 + m->spacing * (m->map3[i][j].x + (m->map3[i][j].z * m->map3[i][j].x) / (m->eye.z - m->map3[i][j].z));
			matrix[i][j].y = HEIGHT / 2 + m->spacing * (m->map3[i][j].y + (m->map3[i][j].z * m->map3[i][j].y) / (m->eye.z - m->map3[i][j].z));
			matrix[i][j].z = m->map3[i][j].z;
			j++;
		}
		i++;
	}
	return (matrix);
}
