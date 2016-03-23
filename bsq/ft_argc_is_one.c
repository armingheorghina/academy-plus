/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argc_is_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 22:21:42 by vdruta            #+#    #+#             */
/*   Updated: 2015/09/24 23:12:05 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_argc_is_one(int argc)
{
	char	*str;
	char	**map;

	if (argc == 1)
	{
		str = ft_open_read_stock(NULL);
		map = ft_map(str, 1);
		if (map != NULL)
		{
			if (ft_val_nr_linii(str, map) == 0 ||
					ft_val_lung_linii(str, map) == 0 ||
					ft_find_number(str) == 0)
				write(2, "map error\n", 10);
		}
		else
			write(2, "map error\n", 10);
	}
}
