/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 15:17:59 by vdruta            #+#    #+#             */
/*   Updated: 2016/03/22 16:55:06 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int argc, char **argv)
{
	char	*str;
	char	**map;
	t_param param;

	if (argc != 2)
	{
		write(1, "usage: ./bsq [ file ]\n", 22);
		exit(0);
	}
	str = ft_open_read_stock(argv[1]);
	ft_argc_bigger_than_1(argc, argv);
	ft_argc_is_one(argc);
	param.plin = ft_find_plin(str);
	param.max = 1;
	param.lin = ft_find_number(str);
	map = ft_map(str, 0);
	param.col = ft_find_1st_line_lenght(map);
	param.vid = ft_find_vid(str);
	param.obst = ft_find_obstacol(str);
	generare_matrice(map, &param);
	return (0);
}
