/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_c_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:23:45 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/03 18:52:53 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_c_(va_list ap, int *bytes, char *descriptor)
{
	unsigned char	c;
	signed char		sc;
	unsigned char	usc;
	char			*findhh;
	char			*str;

	if (ft_strchr(descriptor, 'l'))
		ft_process_cc_(ap, bytes);
	else
	{
		if ((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h' && descriptor[ft_strlen(descriptor) - 1] == 'u')
		{
			usc = va_arg(ap, int);
			ft_putnbr(usc);
			*bytes += ft_strlen(ft_itoa(usc));
		}
		else if ((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h' && (descriptor[ft_strlen(descriptor) - 1] == 'd' || descriptor[ft_strlen(descriptor) - 1] == 'i'))
		{
			sc = va_arg(ap, int);
			ft_putnbr(sc);
			*bytes += ft_strlen(ft_itoa(sc));
		}
		else if ((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h' && descriptor[ft_strlen(descriptor) - 1] == 'o')
		{
			usc = va_arg(ap, int);
			str = ft_itoabase(usc, 8);
			ft_putstr(str);
			*bytes += ft_strlen(str);
		}
		else
		{
			c = va_arg(ap, int);
			ft_putchar(c);
			*bytes = *bytes + 1;
		}
	}
}
