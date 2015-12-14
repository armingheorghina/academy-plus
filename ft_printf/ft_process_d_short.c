/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d_short.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:49:07 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/14 17:49:32 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_d_short(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	short	nbr;
	char 	*str;

	nbr = va_arg(ap, int);
	g_nbr = nbr;
	str = ft_short_to_ascii_base(nbr, 10);
	if (arg.precision)
	{
		str = ft_process_d_precision(str, arg);
		if (nbr < 0)
			str = ft_strjoin("-", str);
	}
	if (nbr < 0 && !arg.precision && !arg.width)
		str = ft_strjoin("-", str);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	if(arg.width)
		str = ft_process_d_width(str, arg);
	if (arg.flag_plus && nbr >= 0)
		ft_process_d_put_flag_plus(bytes, &str, arg);
	else if (arg.flag_space && nbr >= 0)
		ft_process_d_put_flag_space(bytes, &str, arg);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}
