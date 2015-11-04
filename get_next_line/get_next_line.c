/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:05:13 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/04 20:14:09 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //printf

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

int		get_next_line(int const fd, char **line)
{
	static char	*buffs = NULL;
	char		*pos;
	int			ret;
printf("asd\n");
	if (fd == -1)	
		return (-1);
	if (BUFF_SIZE < 1)
		return (-1);
	if (!(buffs = (char*)malloc(sizeof(*buffs) * (BUFF_SIZE + 1))))
		return (-1);
	pos = ft_strchr(buffs, '\n');
	if (pos != NULL)
	{
		*pos = 0;
		*line = ft_strdup(buffs);
		buffs = ft_strcpy(buffs, (pos + 1));
		return (1);
	}
	else if (pos == NULL)
	{
		ret = read(fd, buffs, BUFF_SIZE);
		if (ret == 0)
			return (0);
		get_next_line(fd, line);
	}
	return (1);
}

int		main(void)
{
	int		fd;
	char	**line;

	fd = open("file1", O_RDONLY);
	printf("%d", fd);
	printf("%s", ft_read(fd, line));
//	get_next_line(fd, line);
	
//		write(1, *line, 32);
		//printf("%s", *line);
		//write(1, "Asd", 3);
	
	close(fd);
	return (0);
}
