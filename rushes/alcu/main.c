/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anflorea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 13:11:01 by anflorea          #+#    #+#             */
/*   Updated: 2015/12/21 17:44:36 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alcu.h"

int		ft_validate_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != '\t')
			return (-1);
		i++;
	}
	i = ft_atoi(line);
	if (i <= 0)
		return (-1);
	return (i);
}

void	ft_compute_first(t_alcu *lst)
{
	int		last;
	int		last_first;

	lst->first = 1;
	last_first = 1;
	last = lst->value;
	lst = lst->next;
	while (lst)
	{
		last %= 4;
		if (last_first == 1 && last == 1)
			lst->first = 2;
		else if (last_first == 1)
			lst->first = 1;
		else if (last == 0)
			lst->first = 2;
		else
			lst->first = 1;
		last_first = lst->first;
		last = lst->value;
		lst = lst->next;
	}
}

int		ft_go_next(int fd, t_alcu **lst)
{
	char	*line;

	if (!(*lst))
		return (ft_print_error());
	if (fd > 0 && get_next_line(fd, &line))
		return (ft_print_error());
	ft_compute_first(*lst);
	ft_go_to_menu(lst);
	return (0);
}

int		ft_read(int fd)
{
	t_alcu	*lst;
	char	*line;
	int		nbr;
	int		ok;

	lst = NULL;
	ok = 1;
	ft_clear_screen();
	if (fd == 0)
		ft_putstr("Please enter the map.\n");
	while (ok && get_next_line(fd, &line))
	{
		nbr = ft_validate_line(line);
		if (ft_strcmp(line, ""))
		{
			if (nbr <= 0 || nbr > 10000)
				return (ft_print_error());
			ft_push_back(&lst, nbr);
		}
		else if (ft_strcmp(line, "") && nbr == -1)
			return (ft_print_error());
		else
			ok = 0;
	}
	return (ft_go_next(fd, &lst));
}

int		main(int argc, char **argv)
{
	int	fd;
	int	ret;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (ft_print_error());
	}
	else if (argc == 1)
		fd = 0;
	else
		return (ft_print_error());
	ret = ft_read(fd);
	close(fd);
	return (ret);
}
