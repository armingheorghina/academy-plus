/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_xx_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:57:22 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/03 16:20:34 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_xx_(va_list ap, int *bytes, char *descriptor)
{
	unsigned int 	nbr;
	unsigned long 	ulnbr;
	char			*str;

	if (ft_strchr(descriptor, 'l'))
	{
		ulnbr = va_arg(ap, unsigned long);
		str = ft_itoabbase(ulnbr, 16);
	}
	else
	{
		nbr = va_arg(ap, unsigned int);
		str = ft_itoabbase(nbr, 16);
	}

	if (ft_strchr(descriptor, '#') && nbr != 0)
	{
		ft_putstr("0X");
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 2;
	}
	else
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}
