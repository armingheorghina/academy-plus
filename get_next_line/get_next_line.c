/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:05:13 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/05 15:04:16 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //printf
/*
char	*ft_read(int fd, char **line)
{
	int		ret;
	char	*buffs;

	if (!(buffs = (char*)malloc(sizeof(*buffs) * (BUFF_SIZE + 1))))
		return (NULL);
	ret = read(fd, buffs, BUFF_SIZE);
	buffs[ret] = '\0';
	return (buffs);
	if (ret < 0)
		//return (-1);
	if (ret == 0)
	{
		//return (0);
		//get_next_line(fd, buffs);
	}
	//else
		//get_next_line(fd, buffs);
}
*/
int		get_next_line(int const fd, char **line)
{
	static char	*buffs;
	char		*pos;
	int			ret;
	
	if (fd == -1)	
		return (-1);
	if (BUFF_SIZE < 1)
		return (-1);
	if (!(buffs = (char*)malloc(sizeof(*buffs) * (BUFF_SIZE + 1))))
		return (-1);
	ret = read(fd, buffs, BUFF_SIZE);
		if (ret == 0)
			return (0);
//	while ((pos = ft_strchr(buffs, '\n')) == NULL)
//	{
//		get_next_line(fd, line);
//	}

		printf("%s\n", buffs);
//	pos[0] = '\0';
//	*line = ft_strdup(buffs);
		//printf("%s\n", *line);
//	buffs = ft_strcpy(buffs, (pos + 1));
		//printf("%s", buffs);
	return (1);
}

int		main(void)
{
	int		fd;
	char	**line;

	fd = open("file1", O_RDONLY);
	get_next_line(fd, line);
	get_next_line(fd, line);
//		printf("%s", *line);

	close(fd);
	return (0);
}
