/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anflorea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 13:10:47 by anflorea          #+#    #+#             */
/*   Updated: 2015/12/21 15:32:30 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alcu.h"

int		ft_get_max_number(t_alcu *lst)
{
	int maxi;

	maxi = 0;
	while (lst)
	{
		if (maxi < lst->value)
			maxi = lst->value;
		lst = lst->next;
	}
	return (maxi);
}

void	ft_put_spaces_and_remaining_matches(int value, int spaces)
{
	ft_putnbr(value);
	while (spaces)
	{
		ft_putchar(' ');
		spaces--;
	}
	ft_putstr(":  ");
}

void	ft_clear_screen(void)
{
	int		i;

	i = 0;
	while (i < 120)
	{
		ft_putchar('\n');
		i++;
	}
}

void	ft_print_map(t_alcu *lst)
{
	int	i;
	int	maxi;
	int	spaces;

	maxi = ft_get_max_number(lst);
	ft_putchar('\n');
	while (lst)
	{
		i = 0;
		spaces = ft_strlen((ft_itoa(maxi))) - ft_strlen((ft_itoa(lst->value)));
		ft_put_spaces_and_remaining_matches(lst->value, spaces);
		while (i < lst->value)
		{
			ft_putstr("| ");
			i++;
		}
		ft_putchar('\n');
		lst = lst->next;
	}
	ft_putchar('\n');
}
