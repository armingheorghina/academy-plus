/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d_put_flag_plus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 14:42:07 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/15 16:18:44 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_d_put_flag_plus(int *bytes, char **str, t_arg arg)
{
	if (arg.width > ft_strlen(ft_itoabase(g_nbr, 10)) && g_nbr >= 0 &&
			!arg.precision && !arg.flag_plus)
		*str[0] = '+';
	else if (arg.width > ft_strlen(ft_itoabase(g_nbr, 10)) && g_nbr >= 0 &&
			!arg.precision && arg.flag_zero)
		*str[0] = '+';
	else if (arg.width < ft_strlen(ft_itoabase(g_nbr, 10)))
	{
		ft_putchar('+');
		*bytes += 1;
	}
	else if (arg.flag_minus && arg.width)
	{
		ft_putchar('+');
		*bytes += 1;
	}
}
