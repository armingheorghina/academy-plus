/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_read_stock.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 16:07:44 by vdruta            #+#    #+#             */
/*   Updated: 2016/03/22 15:07:52 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_open_read_stock(char *file_name)
{
	int		fd;
	char	*buf;
	int		i;
	char	*new;

	if (file_name)
	{
		fd = open(file_name, O_RDONLY);
		if (fd < 0)
		{
			write(1, "invalid file\n", 12);
			exit(0);
		}
	}
	else
	{
		fd = -1;
		exit(0);
	}
	buf = (char*)malloc(sizeof(*buf));
	new = (char*)malloc(sizeof(*new) * 100000000);
	i = 0;
	while (read(fd, buf, BUF_SIZE))
	{
		new[i] = buf[0];
		i++;
	}
	new[i] = '\0';
	return (new);
}
