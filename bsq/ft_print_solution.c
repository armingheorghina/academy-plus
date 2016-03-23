/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 18:06:40 by azaha             #+#    #+#             */
/*   Updated: 2015/09/24 22:31:37 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"

void	ft_print_solution(int **matr, t_param *param)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < param->lin)
	{
		j = 0;
		while (j < param->col)
		{
			if (i > (param->pos[0] - param->max) && i <= param->pos[0])
			{
				if (j > (param->pos[1] - param->max) && j <= param->pos[1])
					ft_putchar(param->plin);
				else if (j <= (param->pos[1] - param->max) || j > param->pos[1])
				{
					if (matr[i][j] == 0)
						ft_putchar(param->obst);
					else
						ft_putchar(param->vid);
				}
			}
			else if (matr[i][j] == 0)
				ft_putchar(param->obst);
			else
				ft_putchar(param->vid);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
