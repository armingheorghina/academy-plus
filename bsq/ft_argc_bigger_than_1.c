/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argc_bigger_than_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 15:25:58 by vdruta            #+#    #+#             */
/*   Updated: 2016/03/22 17:00:54 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		ft_argc_bigger_than_1(int argc, char **argv)
{
	char	*str;
	char	**map;
	int		i;

	i = 1;
	while (i < argc)
	{
		str = ft_open_read_stock(argv[i]);
		map = ft_map(str, 0);
		if (map != NULL)
		{
			if (ft_val_nr_linii(str, map) == 0 ||
					ft_val_lung_linii(str, map) == 0 ||
					ft_find_number(str) == 0)
			{
				write(2, "map error\n", 10);
				exit(0);
			}
		}
		else
		{
			write(2, "map error\n", 10);
			exit(0);
		}
		i++;
	}
}
