/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:05:13 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/06 15:08:09 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //printf

int		read_to_stock(int const fd, char **stock)
{
	char	buff[BUFF_SIZE + 1];
	int			ret;
	char        *nstr;

	ret = read(fd, buff, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = '\0';
		nstr = ft_strjoin(*stock, buff);
		if (!nstr)
			return (-1);
		free(*stock);
		*stock = nstr;
	}
	return (ret);
}

int		get_next_line(int const fd, char ** line)
{
	static char	*stock = NULL;
	char		*bn;
	int         ret;

	if (!stock && (stock = (char *)malloc(sizeof(*stock))) == NULL)
		return (-1);
	bn = ft_strchr(stock, '\n');
	while (bn == NULL)
	{
		ret = read_to_stock(fd, &stock);
		if (ret == 0)
		{
			if (ft_strlen((bn = ft_strchr(stock, '\0'))) == ft_strlen(stock))
				return (0);
		}
		else if (ret < 0)
			return (-1);
		else
			bn = ft_strchr(stock, '\n');
	}
	*line = ft_strsub(stock, 0, ft_strlen(stock) - ft_strlen(bn));
	if (!*line)
		return (-1);
	stock = ft_strdup(bn + 1);
	return (1);
}

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("file1", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
	}

	close(fd);
	return (0);
}
