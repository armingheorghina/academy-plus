/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_c_uc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:08:54 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/15 16:10:07 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_c_uc(va_list ap, int *bytes, t_arg arg)
{
	unsigned char	c;

	c = va_arg(ap, int);
	if (arg.flag_minus)
		ft_process_c_flag_minus(c, bytes, arg);
	else if (arg.flag_zero)
		ft_process_c_flag_zero(c, bytes, arg);
	else if (arg.width > 1)
		ft_process_c_width(c, bytes, arg);
	else
	{
		ft_putchar(c);
		*bytes = *bytes + 1;
	}
}
