/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:47:28 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/09 15:37:05 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tetris	*list;

	if (ac == 2)
	{
		list = get_tetris_pieces(av[1]);
		fillit(list);
	}
	else
		print_message_and_exit("usage: ./fillit source_file", 1);
	return (0);
}
