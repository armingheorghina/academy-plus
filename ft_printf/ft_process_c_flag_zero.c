/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_c_flag_zero.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:02:48 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/15 16:04:03 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_c_flag_zero(unsigned char c, int *bytes, t_arg arg)
{
	char	*strp;

	if (arg.width > 1)
	{
		strp = ft_memalloc(arg.width - 1 + 1);
		strp = ft_memset(strp, '0', arg.width - 1);
		ft_putstr(strp);
		*bytes += ft_strlen(strp);
		ft_putchar(c);
		*bytes = *bytes + 1;
	}
}
