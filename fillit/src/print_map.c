/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 20:11:18 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/09 15:08:21 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != 0)
	{
		ft_putendl(map[i]);
		i++;
	}
}

void	print_map_temp(char **map)
{
	int i;

	i = 0;
	while (map[i][0] != '\0')
	{
		ft_putendl(map[i]);
		i++;
	}
}
