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

static int		read_to_stock(int const fd, char **stock)
{
	char	*buff;
	int	ret;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = '\0';
		*stock = ft_strjoin(*stock, buff);
	}
	free(buff);
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
			return (0);
		if (ret < 0)
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
