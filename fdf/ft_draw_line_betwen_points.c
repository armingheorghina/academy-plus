/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line_betwen_points.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:39:08 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/02 16:39:47 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_lines_between_points(t_point **matrix, t_env *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			if (j < m->columns - 1)
				draw_line(matrix[i][j], matrix[i][j + 1], m);
			if (i < m->rows - 1)
				draw_line(matrix[i][j], matrix[i + 1][j], m);
			j++;
		}
		i++;
	}
}
