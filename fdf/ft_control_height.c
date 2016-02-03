/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:59:25 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/03 17:13:34 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_control_height(t_env *m, int control)
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			if (m->map2[i][j].z != 0 && control == 1)
				m->map2[i][j].z *= 2;
			if (m->map2[i][j].z != 0 && control == -1)
				m->map2[i][j].z /= 2;
			if (m->map3[i][j].z != 0 && control == 1)
				m->map3[i][j].z *= 2;
			if (m->map3[i][j].z != 0 && control == -1)
				m->map3[i][j].z /= 2;
			j++;
		}
		i++;
	}
}
