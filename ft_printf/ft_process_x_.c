/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_x_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:08:19 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/03 19:05:38 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_x_(va_list ap, int *bytes, char *descriptor)
{
	unsigned int 	nbr;
	unsigned long 	ulnbr;
	char			*str;
	char			*findhh;
	
	if ((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h')
		ft_process_c_(ap, bytes, descriptor);
	else if (ft_strchr(descriptor, 'l'))
	{
		ulnbr = va_arg(ap, unsigned long);
		str = ft_itoabase(ulnbr, 16);
	}
	else
	{
		nbr = va_arg(ap, unsigned int);
		str = ft_itoabase(nbr, 16);
	}
/* prind side os below*/
	if (ft_strchr(descriptor, '#') && nbr != 0 && !((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h'))
	{
		ft_putstr("0x");
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 2;
	}
	else if (!((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h'))
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}
