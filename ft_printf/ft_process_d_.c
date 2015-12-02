/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:02:56 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/02 18:03:48 by rcalina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_d_(va_list ap, int *bytes, char *descriptor)
{
	int nbr;

	nbr = va_arg(ap, int);
	if (ft_strchr(descriptor, '+') && nbr >= 0)
	{
		ft_putchar('+');
		ft_putnbr(nbr);
		*bytes += ft_strlen(ft_itoa(nbr)) + 1;
	}
	else if (ft_strchr(descriptor, ' ') && nbr >= 0)
	{
		ft_putchar(' ');
		ft_putnbr(nbr);
		*bytes += ft_strlen(ft_itoa(nbr)) + 1;
	}
	else
	{
		ft_putnbr(nbr);
		*bytes += ft_strlen(ft_itoa(nbr));
	}
}
