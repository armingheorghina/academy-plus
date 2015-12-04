/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_xx_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:57:22 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/04 14:25:51 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_xx_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	unsigned int 	nbr;
	unsigned long 	ulnbr;
	uintmax_t		nbr2;
	char			*str;
	char			*findhh;
	
	if ((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h')
		ft_process_c_(ap, bytes, descriptor, arg);
	else if (ft_strchr(descriptor, 'l'))
	{
		ulnbr = va_arg(ap, unsigned long);
		str = ft_itoabbase(ulnbr, 16);
	}
	else if (ft_strchr(descriptor, 'z'))
	{	
		nbr2 = va_arg(ap, uintmax_t);
		str = ft_itoabbase(nbr2, 16);
	}
	else
	{
		nbr = va_arg(ap, unsigned int);
		str = ft_itoabbase(nbr, 16);
	}
/*print side below*/
	if (ft_strchr(descriptor, '#') && nbr != 0 && !((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h'))
	{
		ft_putstr("0X");
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 2;
	}
	else if (!((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h'))
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}
