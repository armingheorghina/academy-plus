
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_valid_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 20:16:23 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/08 20:25:00 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		compare_letter(char **old_map, char **new_map, char letter)
{
	int		row;
	int		col;

	row = 0;
	col = 0;
	while (old_map[row][0] != '\0')
	{
		if (old_map[row][col] == letter)
		{
			if (new_map[row][col] == letter)
				return (0);
			else
				return (-1);
		}
		else if (new_map[row][col] == letter)
			return (1);
		col++;
		if (old_map[row][col] == '\0')
		{
			row++;
			col = 0;
		}
	}
	return (-1);
}

int		new_map_is_better(char **old_map, char **new_map)
{
	char	letter;
	int		result;

	letter = 'A';
	while (1)
	{
		result = compare_letter(old_map, new_map, letter);
		if (result == -1)
			return (0);
		if (result == 1)
			return (1);
		letter++;
	}
	return (0);
}

char	**duplicate_map(char **map)
{
	int		index;
	char	**new_map;

	index = 0;
	while (map[index][0] != '\0')
		index++;
	new_map = (char**)malloc(sizeof(char*) * (index + 1));
	index = 0;
	while (map[index][0] != '\0')
	{
		new_map[index] = ft_strdup(map[index]);
		index++;
	}
	new_map[index] = 0;
	return (new_map);
}

char	**save_valid_map(char **map)
{
	static char **static_map = NULL;
	
	if (map == NULL)
	{
		return (static_map);
	}
	if (static_map == NULL)
	{
		static_map = duplicate_map(map);
	}
	else if (new_map_is_better(static_map, map)) //*TODO free old bad map!!
	{
		static_map = duplicate_map(map);
	}
	/*
	if (map != NULL)
	{
		print_map(static_map);
		write(1, "\n", 1);
	}*/
	return (static_map);
}
