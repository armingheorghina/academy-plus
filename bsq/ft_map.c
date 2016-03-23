/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 15:08:27 by vdruta            #+#    #+#             */
/*   Updated: 2016/03/22 16:00:52 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**ft_map(char *str, int i)
{
	int		j;
	int		k;
	char	**map;

	j = 0;
	map = (char**)malloc(sizeof(char*) * 120000000);
	k = (ft_line_lenght(str) + 1);
	if (str[k] == '\0')
		return (NULL);
	else
	{
		while (str[k] != '\0')
		{
			map[i] = (char*)malloc(sizeof(char) * 999999);
			map[i + 1] = (char*)malloc(sizeof(char) * 999999);
			while (str[k] != '\n')
			{
				map[i][j] = str[k];
				j++;
				k++;
			}
			map[i][j] = '\n';
			j = 0;
			k++;
			i++;
		}
		map[i] = 0;
		return (map);
	}
}
