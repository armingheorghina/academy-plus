/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_oo_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:54:24 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/09 13:51:07 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_oo_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	unsigned long 	nbr;
	char		*str;

	nbr = va_arg(ap, unsigned long);
	str = ft_unsigned_long_to_ascii_base(nbr, 8);
	str = ft_process_d_precision(str, arg);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
	{
		str[0] = '\0';
		if (arg.flag_hash)
			str = ft_strdup("0");
	}   
	if (arg.flag_hash && nbr != 0 && !arg.precision)
		str = ft_strjoin("0", str);
	str = ft_process_d_width(str, arg);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}
