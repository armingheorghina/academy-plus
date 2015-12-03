/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:02:56 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/03 19:56:33 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_d_(va_list ap, int *bytes, char *descriptor)
{
	int			nbr;
	intmax_t	nbr2;
	char	 	*str;
	char		*findhh;

	if ((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h')
		ft_process_c_(ap, bytes, descriptor);
	else if (ft_strchr(descriptor, 'l'))
		ft_process_dd_(ap, bytes, descriptor);
	else if (ft_strchr(descriptor, 'j') || ft_strchr(descriptor, 'z'))
	{
		nbr2 = va_arg(ap, intmax_t);
		str = ft_intmax_t_to_ascii_base(nbr2, 10);
	}
	else
	{
		nbr = va_arg(ap, int);
		str = ft_intmax_t_to_ascii_base(nbr, 10);
	}
/* print side of the file*/	
	if (ft_strchr(descriptor, '+') && nbr >= 0 && !ft_strchr(descriptor, 'l') &&
		!((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h'))
	{
		ft_putchar('+');
		ft_putstr(str);
		*bytes += ft_strlen(str) + 1;
	}
	else if (ft_strchr(descriptor, ' ') && nbr >= 0 && !ft_strchr(descriptor, 'l')
			 && !((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h'))
	{
		ft_putchar(' ');
		ft_putstr(str);
		*bytes += ft_strlen(str) + 1;
	}
	else if (!ft_strchr(descriptor, 'l') && !((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h'))
	{
		ft_putstr(str);
		*bytes += ft_strlen(str);
	}
}
