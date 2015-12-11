/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_uu_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:55:51 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/03 15:38:28 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_uu_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	unsigned long 	nbr;
	char		*str;

	nbr = va_arg(ap, unsigned long);
	g_nbr = 1;
	str = ft_unsigned_long_to_ascii_base(nbr, 10);
	str = ft_process_d_precision(str, arg);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	str = ft_process_d_width(str, arg);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}
