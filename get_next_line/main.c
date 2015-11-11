/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:05:13 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/11 18:04:38 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/* comment the one you want to test. make sure the other 3 are not commented. */
#define READ_FROM_FILE
#define READ_FROM_STDIN
//#define READ_FROM_STDIN_FILE
#define READ_FROM_BINARY_FILE

#ifndef READ_FROM_FILE
int		main(void)
{
	int	fd;
	char	*line;

	fd = open("file4", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
	}
	close(fd);
	return (0);
}
#endif

#ifndef READ_FROM_STDIN
int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	if (argc < 1)
		return (0);
	*argv = NULL;
	fd = 0;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
	}
	close(fd);
	return (0);
}
#endif

#ifndef READ_FROM_STDIN_FILE
int	main(int argc, char **argv)
{
	int	fd;
	char	*line;
	int	i;

	if (argc < 2)
	{
		printf("usage: ./test_gnl file1 file2 etc.\n");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			printf("%s\n", line);
		}
		close(fd);
		i++;
	}
	return (0);
}
#endif

#ifndef READ_FROM_BINARY_FILE
int		main()
{
	int		fd;
	char	*line;

	line = (char*)malloc(sizeof(*line));
	fd = open("file2.bin", O_RDONLY);
	get_next_line(fd, &line);
	close(fd);

	printf("%s\n", line);

	return (0);
}
#endif
