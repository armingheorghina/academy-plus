/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_s_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:43:39 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/28 16:10:00 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_s_(va_list ap, int *bytes)
{
	char *str;

	str = va_arg(ap, char *);
	if (str)
	{	ft_putstr(str);
		*bytes += ft_strlen(str);
	}	
	else
	{
		ft_putstr("(null)");
		*bytes += 6;
	}
}
