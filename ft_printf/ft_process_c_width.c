/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_c_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:06:43 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/15 16:08:24 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_c_width(unsigned char c, int *bytes, t_arg arg)
{
	char	*strp;

	strp = ft_memalloc(arg.width - 1 + 1);
	strp = ft_memset(strp, ' ', arg.width - 1);
	ft_putstr(strp);
	*bytes += ft_strlen(strp);
	ft_putchar(c);
	*bytes = *bytes + 1;
}
