/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:03:58 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/02 17:54:55 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_damn_norminette(t_env *m, int i, int j)
{
	m->map2[i][j].x -= 1;
	m->map2[i][j].y -= 1;
}

void	ft_damn_norminette2(t_env *m, int i, int j)
{
	m->map2[i][j].x += 1;
	m->map2[i][j].y += 1;
}

void	ft_damn_norminette3(t_env *m, int i, int j)
{
	m->map2[i][j].x -= 1;
	m->map2[i][j].y += 1;
}

void	ft_move(t_env *m, int keycode)
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			if (keycode == 126)
				ft_damn_norminette(m, i, j);
			if (keycode == 125)
				ft_damn_norminette2(m, i, j);
			if (keycode == 123)
				ft_damn_norminette3(m, i, j);
			if (keycode == 124)
			{
				m->map2[i][j].x += 1;
				m->map2[i][j].y -= 1;
			}
			j++;
		}
		i++;
	}
}
