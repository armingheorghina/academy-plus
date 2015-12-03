/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_u_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:53:10 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/03 18:14:28 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_u_(va_list ap, int *bytes, char *descriptor)
{
	unsigned int 	nbr;
	char			*str;
	char			*findhh;

	if ((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h')
		ft_process_c_(ap, bytes, descriptor);
	else if (ft_strchr(descriptor, 'l'))
		ft_process_uu_(ap, bytes);
	else
	{
		nbr = va_arg(ap, unsigned int);
		str = ft_itoabase(nbr, 10);
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}
