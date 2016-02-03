/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:02:54 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/03 17:20:21 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate(t_env *m, int keycode) //TODO rotate for perspective
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			if (keycode == 114) //insert
			{
				m->map3[i][j].x = m->map3[i][j].x;
				m->map3[i][j].y = m->map3[i][j].y;
			}
			if (keycode == 117) //delete
			{
				m->map3[i][j].x = m->map3[i][j].x;
				m->map3[i][j].y = m->map3[i][j].y;
			}
			j++;
		}
		i++;
	}
}
