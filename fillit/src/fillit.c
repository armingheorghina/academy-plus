/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 19:41:42 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/09 16:02:45 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned char	get_map_size(t_tetris *list)
{
	unsigned char	pieces;
	unsigned char	size;
	t_tetris		*start;

	pieces = 0;
	start = list;
	while (start)
	{
		pieces++;
		start = start->next;
	}
	size = 0;
	while (size * size < pieces * 4)
		size++;
	return (size);
}

char		*create_map(unsigned char size)
{
	char	*map;
	int		index;

	map = (char*)malloc(sizeof(char) * ((size + 1) * (size + 1)));
	index = 0;
	while (index < size)
	{
		ft_memset(map + index * (size + 1), '.', size);
		map[(index + 1) * (size + 1) - 1] = '\n';
		index++;
	}
	ft_memset(map + index * (size + 1), '\0', size + 1);
	return (map);
}

void		fillit(t_tetris *list)
{
	char				*map;
	unsigned char		size;

	size = get_map_size(list);
	change_coordinates(list, size);
	while (1)
	{
		map = create_map(size);
		backtrack(list, map);
		size++;
		increment_coordinates(list, size);
	}
}
