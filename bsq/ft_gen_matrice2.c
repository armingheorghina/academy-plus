/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_matrice2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 22:05:36 by azaha             #+#    #+#             */
/*   Updated: 2015/09/24 22:17:06 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_gen_matrice(char **map, int **m, t_param *param)
{
	int i;
	int j;

	i = 1;
	while (i < param->lin)
	{
		j = 1;
		while (j < param->col)
		{
			if (map[i][j] == param->vid)
				m[i][j] = minim(m[i - 1][j], m[i - 1][j - 1], m[i][j - 1]) + 1;
			else
				m[i][j] = 0;
			if (m[i][j] > param->max)
			{
				param->pos[0] = i;
				param->pos[1] = j;
				param->max = m[i][j];
			}
			j++;
		}
		i++;
	}
}
