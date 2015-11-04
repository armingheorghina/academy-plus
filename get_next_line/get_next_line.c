/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:05:13 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/04 16:07:17 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static char	*buff = NULL;
	char		*pos;
	int			result;
	
	if (BUFF_SIZE < 1 || !line)
		return (-1);
	if (!(buff = (char*)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	pos = ft_strchr(buff, '\n');
	if (pos != NULL)
	{
		*pos = '\0';
		*line = ft_strdup(buff);
		buff = ft_strcpy(buff, (pos + 1));

	}
	else if (pos == NULL)
//		result = ft_read_line();
		return (0);
	return (0);
}

int		main(void)
{
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE];

	fd = open("file1", O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		get_next_line(fd, buff);
//	while (get_next_line(fd, &line) > 0)
//		ft_putendl(line);
	return (0);
}
