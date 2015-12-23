/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anflorea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 13:10:38 by anflorea          #+#    #+#             */
/*   Updated: 2015/12/21 13:47:24 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alcu.h"

int		ft_validate_user_input(char *line)
{
	int	nbr;
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != '\t')
			return (-1);
		i++;
	}
	nbr = ft_atoi(line);
	return (nbr);
}

int		get_user_input(int this_line)
{
	char	*line;
	int		nbr;
	int		ok;

	ok = 1;
	ft_putstr("Insert the number of matches you want to remove: ");
	while (ok)
	{
		get_next_line(0, &line);
		nbr = ft_validate_user_input(line);
		if (nbr >= 1 && nbr <= 3 && nbr <= this_line)
			ok = 0;
		else
			ft_putstr("Invalid input. Please try again: ");
	}
	return (nbr);
}
