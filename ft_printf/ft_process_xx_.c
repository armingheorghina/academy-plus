/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_xx_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:57:22 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/15 17:40:17 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_xx_lm_j(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	uintmax_t	nbr;
	char		*str;

	nbr = va_arg(ap, uintmax_t);
	str = ft_itoabbase(nbr, 16);
	g_nbr = 1;
	str = ft_process_d_precision(str, arg);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	if (arg.flag_hash && nbr != 0)
		str = ft_strjoin("0X", str);
	str = ft_process_d_width(str, arg);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}

void	ft_process_xx_lm_ll(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	unsigned long long	nbr;
	char				*str;

	nbr = va_arg(ap, unsigned long long);
	str = ft_itoabbase(nbr, 16);
	g_nbr = 1;
	str = ft_process_d_precision(str, arg);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	if (arg.flag_hash && nbr != 0)
		str = ft_strjoin("0X", str);
	str = ft_process_d_width(str, arg);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}

void	ft_process_xx_lm_h(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	unsigned short	nbr;
	char			*str;

	nbr = va_arg(ap, unsigned int);
	str = ft_itoabbase(nbr, 16);
	g_nbr = 1;
	str = ft_process_d_precision(str, arg);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	if (arg.flag_hash && nbr != 0)
		str = ft_strjoin("0X", str);
	str = ft_process_d_width(str, arg);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}

void	ft_process_xx_no_lm(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	unsigned int	nbr;
	char			*str;

	nbr = va_arg(ap, unsigned int);
	str = ft_itoabbase(nbr, 16);
	g_nbr = 1;
	str = ft_process_d_precision(str, arg);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	if (arg.flag_hash && nbr != 0)
		str = ft_strjoin("0X", str);
	str = ft_process_d_width(str, arg);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}

void	ft_process_xx_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	if (arg.lm_hh)
		ft_process_c_(ap, bytes, descriptor, arg);
	else if (arg.lm_h)
		ft_process_xx_lm_h(ap, bytes, descriptor, arg);
	else if (arg.lm_l)
		ft_process_xx_lm_l(ap, bytes, descriptor, arg);
	else if (arg.lm_ll)
		ft_process_xx_lm_ll(ap, bytes, descriptor, arg);
	else if (arg.lm_j)
		ft_process_xx_lm_j(ap, bytes, descriptor, arg);
	else if (arg.lm_z)
		ft_process_xx_lm_z(ap, bytes, descriptor, arg);
	else
		ft_process_xx_no_lm(ap, bytes, descriptor, arg);
}
