/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:23:48 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/21 16:43:24 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alcu.h"

int		ft_print_error(void)
{
	write(2, "ERROR\n", 6);
	return (0);
}

void	ft_print_winner(int winner)
{
	int		fd;

	ft_putchar('\n');
	if (winner == 0)
	{
		fd = open("files/you_win.txt", O_RDONLY);
		ft_print_file(fd);
		close(fd);
	}
	else
	{
		fd = open("files/you_lose.txt", O_RDONLY);
		ft_print_file(fd);
		close(fd);
	}
}

void	ft_print_file(int fd)
{
	char	*line;

	while (get_next_line(fd, &line))
		ft_putendl(line);
}

void	ft_print_welcome_msg(void)
{
	int fd;

	fd = open("files/alnum.txt", O_RDONLY);
	ft_print_file(fd);
	close(fd);
	fd = open("files/play_a_game.txt", O_RDONLY);
	ft_print_file(fd);
	close(fd);
	ft_putchar('\n');
}
