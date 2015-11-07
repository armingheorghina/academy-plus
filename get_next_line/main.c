/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:05:13 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/06 15:08:09 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	int	fd;
//	int	fd2;
	char	*line;

	fd = open("file1", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
	}
/*	//make it work to get 2nd bonus
	fd = open("file1", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	
	fd2 = open("file4", O_RDONLY);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	close(fd2);
*/
	close(fd);
	return (0);
}
