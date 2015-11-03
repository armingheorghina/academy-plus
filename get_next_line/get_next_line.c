/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:05:13 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/03 14:10:20 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_next_line(int const fd, char ** line)
{
	
}

int		main(void)
{
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE + 1];

	if (!(fd = open("file1", O_RDONLY)))
		return (0);
	while (ret = read(fd, buff, BUFF_SIZE))
	{
		buff[ret] = '\0';
	}
	return (0);
}
