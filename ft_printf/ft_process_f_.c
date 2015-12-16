/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_f_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:42:55 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/16 11:28:29 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_f_float(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	double	nbr;
	char	*str;
	char	*dot_pos;

	nbr = va_arg(ap, double);
	g_nbr = nbr;
	str = ft_ftoa(nbr, 6);
	if (arg.precision)
		str = ft_ftoa(nbr, arg.precision);
	if (nbr < 0 && !arg.precision && !arg.width)
		str = ft_strjoin("-", str);
	if (arg.precision == 0 && ft_strchr(descriptor, '.'))
	{
		dot_pos = ft_strchr(str, '.');
		str = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(dot_pos));
	}
	if (arg.width)
		str = ft_process_d_width(str, arg);
	if (arg.flag_plus && nbr >= 0)
		ft_process_d_put_flag_plus(bytes, &str, arg);
	else if (arg.flag_space && nbr >= 0)
		ft_process_d_put_flag_space(bytes, &str, arg);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}

void	ft_process_f_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	ft_process_f_float(ap, bytes, descriptor, arg);
}
