/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:51:38 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/27 23:41:46 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_int_map(t_env *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			ft_putnbr(m->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_print_cmap(char **cmap)
{
	int i;

	i = 0;
	while (cmap[i])
	{
		ft_putstr(cmap[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_print_struct_matrix(t_env *m)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			ft_putnbr(m->map2[i][j].x);
			ft_putchar(' ');
			ft_putnbr(m->map2[i][j].y);
			ft_putchar(' ');
			ft_putnbr(m->map2[i][j].z);
			ft_putchar(' ');
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
