/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_u_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:53:10 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/07 19:10:04 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_u_lm_ll(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	unsigned long long 	nbr;
	char		*str;

	nbr = va_arg(ap, unsigned long long);
	str = ft_unsigned_long_long_to_ascii_base(nbr, 10);
	str = ft_process_d_precision(str, arg);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	str = ft_process_d_width(str, arg);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}

void	ft_process_u_lm_j(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	uintmax_t nbr;
	char		*str;

	nbr = va_arg(ap, uintmax_t);
	str = ft_uintmax_t_to_ascii_base(nbr, 10);
	str = ft_process_d_precision(str, arg);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	str = ft_process_d_width(str, arg);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}

void	ft_process_u_lm_z(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	size_t	nbr;
	char	*str;

	nbr = va_arg(ap, size_t);
	str = ft_size_t_to_ascii_base(nbr, 10);
	str = ft_process_d_precision(str, arg);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	str = ft_process_d_width(str, arg);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}

void	ft_process_u_uint(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	unsigned int 	nbr;
	char			*str;
	
	nbr = va_arg(ap, unsigned int);
	str = ft_unsigned_int_to_ascii_base(nbr, 10);
	str = ft_process_d_precision(str, arg);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	str = ft_process_d_width(str, arg);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}

void	ft_process_u_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{

	if (arg.lm_hh)
		ft_process_c_(ap, bytes, descriptor, arg);
	else if (arg.lm_l)
		ft_process_uu_(ap, bytes);
	else if (arg.lm_ll)
		ft_process_u_lm_ll(ap, bytes, descriptor, arg);
	else if (arg.lm_j)
		ft_process_u_lm_j(ap, bytes, descriptor, arg);
	else if (arg.lm_z)
		ft_process_u_lm_z(ap, bytes, descriptor, arg);
	else
		ft_process_u_uint(ap, bytes, descriptor, arg);
}
