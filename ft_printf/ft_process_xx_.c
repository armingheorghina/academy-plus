/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_xx_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:57:22 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/02 12:58:11 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_xx_(va_list ap, int *bytes)
{
	unsigned int 	nbr;
	char		*str;

	nbr = va_arg(ap, unsigned int);
	str = ft_itoabbase(nbr, 16);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}
