/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_dd_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:59:49 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/03 15:29:52 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_dd_(va_list ap, int *bytes, char *descriptor)
{
	long	 		nbr;
	unsigned long	ulnbr;
	char 			*str;

	nbr = va_arg(ap, long);
	if (nbr < 0)
	{
		ulnbr = -1 * nbr;
		str = ft_itoabase(ulnbr, 10);
		ft_putstr(ft_strjoin("-", str));
		*bytes += ft_strlen(str) + 1;
	}
	else if (ft_strchr(descriptor, '+') && nbr >= 0)
	{
		ft_putchar('+');
		str = ft_itoabase(nbr, 10);
		ft_putstr(str);
		*bytes += ft_strlen(str) + 1;
	}
	else if (ft_strchr(descriptor, ' ') && nbr >= 0)
	{
		ft_putchar(' ');
		str = ft_itoabase(nbr, 10);
		ft_putstr(str);
		*bytes += ft_strlen(str) + 1;
	}
	else
	{
		str = ft_itoabase(nbr, 10);
		ft_putstr(str);
		*bytes += ft_strlen(str);
	}

}
