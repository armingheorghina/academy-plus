/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_c_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:23:45 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/15 16:11:51 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_c_hhu(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	unsigned char	usc;
	unsigned int	nbr;
	char			*str;

	usc = va_arg(ap, int);
	str = ft_itoabase(usc, 10);
	g_nbr = 1;
	nbr = usc;
	str = ft_process_d_precision(str, arg);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	str = ft_process_d_width(str, arg);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}

void	ft_process_c_hhd(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	signed char	sc;
	int			nbr;
	char		*str;

	sc = va_arg(ap, int);
	str = ft_int_to_ascii_base(sc, 10);
	nbr = sc;
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
	if (arg.width)
		str = ft_process_d_width(str, arg);
	if (arg.flag_plus && nbr >= 0)
		ft_process_d_put_flag_plus(bytes, &str, arg);
	else if (arg.flag_space && nbr >= 0)
		ft_process_d_put_flag_space(bytes, &str, arg);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}

void	ft_process_c_hho(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	unsigned char	usc;
	unsigned int	nbr;
	char			*str;

	usc = va_arg(ap, int);
	str = ft_itoabase(usc, 8);
	g_nbr = 1;
	nbr = usc;
	str = ft_process_d_precision(str, arg);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	str = ft_process_d_width(str, arg);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}

void	ft_process_c_hhxxx(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	unsigned char	usc;
	unsigned int	nbr;
	char			*str;

	usc = va_arg(ap, int);
	if (descriptor[ft_strlen(descriptor) - 1] == 'x')
		str = ft_itoabase(usc, 16);
	else
		str = ft_itoabbase(usc, 16);
	g_nbr = 1;
	nbr = usc;
	str = ft_process_d_precision(str, arg);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	str = ft_process_d_width(str, arg);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}

void	ft_process_c_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	if (arg.lm_l)
		ft_process_cc_(ap, bytes);
	else if (arg.lm_hh && descriptor[ft_strlen(descriptor) - 1] == 'u')
		ft_process_c_hhu(ap, bytes, descriptor, arg);
	else if (arg.lm_hh && (descriptor[ft_strlen(descriptor) - 1] == 'd' ||
				descriptor[ft_strlen(descriptor) - 1] == 'i'))
		ft_process_c_hhd(ap, bytes, descriptor, arg);
	else if (arg.lm_hh && descriptor[ft_strlen(descriptor) - 1] == 'o')
		ft_process_c_hho(ap, bytes, descriptor, arg);
	else if (arg.lm_hh && descriptor[ft_strlen(descriptor) - 1] == 'x')
		ft_process_c_hhxxx(ap, bytes, descriptor, arg);
	else if (arg.lm_hh && descriptor[ft_strlen(descriptor) - 1] == 'X')
		ft_process_c_hhxxx(ap, bytes, descriptor, arg);
	else
		ft_process_c_uc(ap, bytes, arg);
}
