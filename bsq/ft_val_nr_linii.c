/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_nr_linii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 15:11:33 by vdruta            #+#    #+#             */
/*   Updated: 2016/03/22 16:59:48 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_val_nr_linii(char *str, char **map)
{
	int x;
	int y;

	x = ft_find_number(str);
	y = ft_find_map_lines(map);
	if (x != y)
	{
		return (0);
	}
	return (1);
}
