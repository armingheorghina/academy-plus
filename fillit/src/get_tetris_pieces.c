/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetris_pieces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:11:37 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/09 15:46:46 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*get_tetris_pieces(char *filename)
{
	t_tetris	*tetriminos;
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_message_and_exit("error", 2);
	tetriminos = NULL;
	get_tetriminos(&tetriminos, fd);
	return (tetriminos);
}
