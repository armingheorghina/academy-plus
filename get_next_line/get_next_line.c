/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:05:13 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/06 12:57:53 by vdruta           ###   ########.fr       */
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
/*
   int		get_next_line(int const fd, char **line)
   {
   static char	*stock;
   char		*pos;
   int			ret;

   if (fd == -1)	
   return (-1);
   if (BUFF_SIZE < 1)
   return (-1);
   stock = (char*)malloc(sizeof(*stock) * (BUFF_SIZE + 1));
   if (!stock)
   return (-1);
   pos = ft_strchr(stock, '\n');
   while (pos == NULL)
   {
   ret = read(fd, stock, BUFF_SIZE);

   }
 *line = ft_strsub(stock, 0, pos - stock);
 pos = ft_strdup(pos + 1);
 free (stock);
 stock = pos;
 return (1);
 }
 */

int	read_from_fd_into_stock(int const fd, char **stock)
{
	static char	buff[BUFF_SIZE+1] = { '\n' };
	int			read_bytes;
	char        *nstr;

	read_bytes = read(fd, buff, BUFF_SIZE);
	if (read_bytes > 0)
	{
		buff[read_bytes] = '\0';
		nstr = ft_strjoin(*stock, buff);
		if (!nstr)
			return (-1);
		free(*stock);
		*stock = nstr;
	}
	return (read_bytes);
}

int get_next_line(int const fd, char ** line)
{
	static char	*stock = NULL;
	char		*endl_index;
	int         ret;

	if (!stock && (stock = (char *)malloc(sizeof(*stock))) == NULL)
		return (-1);
	endl_index = ft_strchr(stock, '\n');
	while (endl_index == NULL)
	{
		ret = read_from_fd_into_stock(fd, &stock);
		if (ret == 0)
		{
			if ( (endl_index = ft_strchr(stock, '\0')) == stock )
				return (0);
		} else if (ret < 0)
			return (-1);
		else
			endl_index = ft_strchr(stock, '\n');
	}
	*line = ft_strsub(stock, 0, endl_index - stock);
	if (!*line)
		return (-1);
	//endl_index = ft_strdup(endl_index + 1);
	//free(stock);
	//stock = endl_index;
	stock = ft_strdup(endl_index + 1);
	//free(stock);
	//stock = endl_index;
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
