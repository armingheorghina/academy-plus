/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_x_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:08:19 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/07 18:02:40 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	ft_process_x_lm_l(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	unsigned long 	nbr;
	char			*str;

	nbr = va_arg(ap, unsigned long);
	str = ft_unsigned_long_to_ascii_base(nbr, 16);
		str = ft_process_d_precision(str, arg);
		if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
			str[0] = '\0';
		str = ft_process_d_width(str, arg);
	if (arg.flag_hash && nbr != 0)
	{
		ft_putstr("0x");
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 2;
	}
	else
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}

void	ft_process_x_lm_ll(va_list ap, int *bytes, char *descriptor, t_arg arg)
{	
	unsigned long long 	nbr;
	char	*str;

	nbr = va_arg(ap, unsigned long long);
	str = ft_unsigned_long_long_to_ascii_base(nbr, 16);
		str = ft_process_d_precision(str, arg);
		if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
			str[0] = '\0';
		str = ft_process_d_width(str, arg);
	if (arg.flag_hash && nbr != 0)
	{
		ft_putstr("0x");
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 2;
	}
	else
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}

void	ft_process_x_lm_z(va_list ap, int *bytes, char *descriptor, t_arg arg)
{	
	size_t 	nbr;
	char	*str;
	nbr = va_arg(ap, size_t);
	str = ft_size_t_to_ascii_base(nbr, 16);
		str = ft_process_d_precision(str, arg);
		if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
			str[0] = '\0';
		str = ft_process_d_width(str, arg);
	if (arg.flag_hash && nbr != 0)
	{
		ft_putstr("0x");
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 2;
	}
	else
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}

void	ft_process_x_lm_j(va_list ap, int *bytes, char *descriptor, t_arg arg)
{	
	uintmax_t 	nbr;
	char	*str;

	nbr = va_arg(ap, uintmax_t);
	str = ft_uintmax_t_to_ascii_base(nbr, 16);
		str = ft_process_d_precision(str, arg);
		if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
			str[0] = '\0';
		str = ft_process_d_width(str, arg);
	if (arg.flag_hash && nbr != 0)
	{
		ft_putstr("0x");
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 2;
	}
	else
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}
void	ft_process_x_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	unsigned int 	nbr;
	char			*str;

	if (arg.lm_hh)
		ft_process_c_(ap, bytes, descriptor, arg);
	else if (arg.lm_l)
		ft_process_x_lm_l(ap, bytes, descriptor, arg);
	else if (arg.lm_ll)
		ft_process_x_lm_ll(ap, bytes, descriptor, arg);
	else if (arg.lm_j)
		ft_process_x_lm_j(ap, bytes, descriptor, arg);
	else if (arg.lm_z)
		ft_process_x_lm_z(ap, bytes, descriptor, arg);
	else
	{
		nbr = va_arg(ap, unsigned int);
		str = ft_itoabase(nbr, 16);
		str = ft_process_d_precision(str, arg);
		if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
			str[0] = '\0';
		str = ft_process_d_width(str, arg);
		if (arg.flag_hash && nbr != 0)
		{
			ft_putstr("0x");
			ft_putstr(str);
			*bytes = *bytes + ft_strlen(str) + 2;
		}
		else
		{
			ft_putstr(str);
			*bytes = *bytes + ft_strlen(str);
		}
	}
}
