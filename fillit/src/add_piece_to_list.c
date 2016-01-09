/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_piece_to_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 18:12:34 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/09 15:59:49 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		coordinates_are_equal(unsigned char *one, unsigned char *two)
{
	int		index;

	index = 0;
	while (index < 8)
	{
		if (one[index] != two[index])
			return (0);
		index++;
	}
	return (1);
}

static t_tetris	*create_new_tetris_node(t_tetris *tetriminos,
						unsigned char *coordinates, char letter)
{
	t_tetris	*new_node;
	t_tetris	*node;
	
	new_node = malloc(sizeof(t_tetris));
	new_node->coordinates = coordinates;
	new_node->letter = letter;
	new_node->clone = 0;
	node = tetriminos;
	while (node)
	{
		if (coordinates_are_equal(coordinates, node->coordinates))
		{
			new_node->clone = node->letter;
			break;
		}
		node = node->next;
	}
	new_node->next = NULL;
	return (new_node);
}

static void		add_new_tetris_node(t_tetris **tetriminos, unsigned char *coordinates,
						char letter)
{
	t_tetris	*new_node;
	t_tetris	*node;

	new_node = create_new_tetris_node(*tetriminos, coordinates, letter);
	node = *tetriminos;
	while (node->next)
		node = node->next;
	node->next = new_node;
}

void			add_piece_to_list(t_tetris **tetriminos, unsigned char *coordinates,
						char letter)
{
	if (!(*tetriminos))
		(*tetriminos) = create_new_tetris_node(*tetriminos, coordinates, letter);
	else
		add_new_tetris_node(tetriminos, coordinates, letter);
}
