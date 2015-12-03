/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_c_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:23:45 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/03 19:09:44 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_c_hhu(va_list ap, int *bytes)
{
	unsigned char	usc;

	usc = va_arg(ap, int);
	ft_putnbr(usc);
	*bytes += ft_strlen(ft_itoa(usc));
}

void	ft_process_c_hhd(va_list ap, int *bytes)
{
	signed char		sc;

	sc = va_arg(ap, int);
	ft_putnbr(sc);
	*bytes += ft_strlen(ft_itoa(sc));
}

void	ft_process_c_hho(va_list ap, int *bytes)
{
	unsigned char	usc;
	char		*str;

	usc = va_arg(ap, int);
	str = ft_itoabase(usc, 8);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}

void	ft_process_c_hhxxx(va_list ap, int *bytes, char *descriptor)
{
	unsigned char	usc;
	char		*str;

	usc = va_arg(ap, int);
	if (descriptor[ft_strlen(descriptor) - 1] == 'x')
		str = ft_itoabase(usc, 16);
	else if (descriptor[ft_strlen(descriptor) - 1] == 'X')
		str = ft_itoabbase(usc, 16);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}

void	ft_process_c_(va_list ap, int *bytes, char *descriptor)
{
	unsigned char	c;
	char		*findhh;

	if (ft_strchr(descriptor, 'l'))
		ft_process_cc_(ap, bytes);
	else if ((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h' && descriptor[ft_strlen(descriptor) - 1] == 'u')
		ft_process_c_hhu(ap, bytes);
	else if ((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h' && (descriptor[ft_strlen(descriptor) - 1] == 'd' || descriptor[ft_strlen(descriptor) - 1] == 'i'))
		ft_process_c_hhd(ap, bytes);
	else if ((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h' && descriptor[ft_strlen(descriptor) - 1] == 'o')
		ft_process_c_hho(ap, bytes);
	else if ((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h' && descriptor[ft_strlen(descriptor) - 1] == 'x')
		ft_process_c_hhxxx(ap, bytes, descriptor);
	else if ((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h' && descriptor[ft_strlen(descriptor) - 1] == 'X')
		ft_process_c_hhxxx(ap, bytes, descriptor);
	else
	{
		c = va_arg(ap, int);
		ft_putchar(c);
		*bytes = *bytes + 1;
	}
}
