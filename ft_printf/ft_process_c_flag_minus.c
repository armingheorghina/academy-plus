/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_c_flag_minus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:59:19 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/15 16:00:33 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_c_flag_minus(unsigned char c, int *bytes, t_arg arg)
{
	char	*strp;

	if (arg.width > 1)
	{
		ft_putchar(c);
		*bytes = *bytes + 1;
		strp = ft_memalloc(arg.width - 1 + 1);
		strp = ft_memset(strp, ' ', arg.width - 1);
		ft_putstr(strp);
		*bytes += ft_strlen(strp);
	}
}
