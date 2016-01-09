/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:57:41 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/09 15:45:11 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**get_piece(int fd)
{
	char	**piece;
	int		index;

	piece = (char**)malloc(sizeof(char*) * 4);
	index = 0;
	while (index < 4)
	{
		if (get_next_line(fd, piece + index) < 1)
			print_message_and_exit("error", 2);
		index++;
	}
	return (piece);
}
