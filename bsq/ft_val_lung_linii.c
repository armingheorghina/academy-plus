/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_lung_linii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 15:15:21 by vdruta            #+#    #+#             */
/*   Updated: 2016/03/22 17:00:53 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_val_lung_linii(char *str, char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i] != 0)
	{
		while (map[i][j] != '\n')
		{
			if (map[i][j] != ft_find_vid(str) &&
					map[i][j] != ft_find_obstacol(str))
			{
				return (0);
			}
			j++;
		}
		if (j != ft_find_1st_line_lenght(map))
		{
			return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}
