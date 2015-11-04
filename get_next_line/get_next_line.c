/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:05:13 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/04 13:20:59 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static char	*buff = NULL;
	char		*pos;
	int			ret;
	
	if (BUFF_SIZE < 1 || !line)
		return (-1);
	if (!(buff = (char*)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	pos = ft_strchr(buff, '\n');
	if (pos == NULL)
	{
		ret = ft_read_fd_to_stock(fd, &stock);
		if (ret < 0)
			return (-1);
		if (ret == 0)
	}
	else if (pos != NULL)
	{
		
	}

}

int		main(void)
{
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE];

	fd = open("file1", O_RDONLY);
	if (fd == -1)
		return (0);
	while (ret = read(fd, buff, BUFF_SIZE))
		get_next_line(fd, buff);
	return (0);
}
