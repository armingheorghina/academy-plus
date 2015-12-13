/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d_put_flag_space.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 12:47:06 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/13 12:52:54 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_d_put_flag_space(int *bytes, char **str, t_arg arg)
{
	if (arg.width > ft_strlen(ft_itoabase(g_nbr, 10)) && g_nbr >= 0 && !arg.precision && !arg.flag_space)
		*str[0] = ' ';
	else if (arg.width > ft_strlen(ft_itoabase(g_nbr, 10)) && g_nbr >= 0 && !arg.precision && arg.flag_space)
		*str[0] = ' ';
	else if (!arg.flag_space)
	{
		ft_putchar(' ');
		*bytes += 1;
	}
	else if (!arg.width)
	{
		ft_putchar(' ');
		*bytes += 1;
	}
}
