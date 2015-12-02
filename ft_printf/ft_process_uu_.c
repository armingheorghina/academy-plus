/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_uu_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:55:51 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/02 12:56:27 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_uu_(va_list ap, int *bytes)
{
	unsigned long 	nbr;
	char		*str;

	nbr = va_arg(ap, unsigned long);
	str = ft_itoabase(nbr, 10);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}
