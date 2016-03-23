/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 12:54:54 by vdruta            #+#    #+#             */
/*   Updated: 2016/03/22 16:01:56 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_map(char **map)
{
	int i;
	int j;

	i = 0;
	printf("%s", map[8]);
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
