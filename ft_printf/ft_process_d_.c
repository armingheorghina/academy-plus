/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:02:56 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/07 19:06:52 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_d_put_flag_plus(int *bytes)
{
	ft_putchar('+');
	*bytes += 1;
}

void	ft_process_d_put_flag_space(int *bytes)
{
	ft_putchar(' ');
	*bytes += 1;
}

void	ft_process_d_intmax_t(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	intmax_t	nbr;
	intmax_t	lnbr;
	char	 	*str;

	nbr = va_arg(ap, intmax_t);
	lnbr = nbr;
	if (nbr < 0)
		lnbr = -nbr;
	str = ft_intmax_t_to_ascii_base(lnbr, 10);
	str = ft_process_d_precision(str, arg);
	if (nbr < 0)
		str = ft_strjoin("-", str);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	str = ft_process_d_width(str, arg);
	if (arg.flag_plus && nbr >= 0)
		ft_process_d_put_flag_plus(bytes);
	else if (arg.flag_space && nbr >= 0)
		ft_process_d_put_flag_space(bytes);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}

void	ft_process_d_ssize_t(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	ssize_t	nbr;
	ssize_t	lnbr;
	char 	*str;

	nbr = va_arg(ap, ssize_t);
	lnbr = nbr;
	if (nbr < 0)
		lnbr = -nbr;
	str = ft_ssize_t_to_ascii_base(lnbr, 10);
	str = ft_process_d_precision(str, arg);
	if (nbr < 0)
		str = ft_strjoin("-", str);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	str = ft_process_d_width(str, arg);
	if (arg.flag_plus && nbr >= 0)
		ft_process_d_put_flag_plus(bytes);
	else if (arg.flag_space && nbr >= 0)
		ft_process_d_put_flag_space(bytes);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}

void	ft_process_d_short(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	short	nbr;
	int		lnbr;
	char 	*str;

	nbr = va_arg(ap, int);
	lnbr = nbr;
	if (nbr < 0)
		lnbr = -nbr;
	str = ft_short_to_ascii_base(lnbr, 10);
	str = ft_process_d_precision(str, arg);
	if (nbr < 0)
		str = ft_strjoin("-", str);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	str = ft_process_d_width(str, arg);
	if (arg.flag_plus && nbr >= 0)
		ft_process_d_put_flag_plus(bytes);
	else if (arg.flag_space && nbr >= 0)
		ft_process_d_put_flag_space(bytes);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}

void	ft_process_d_long_long(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	long long	nbr;
	long long	lnbr;
	char 		*str;

	nbr = va_arg(ap, long long);
	lnbr = nbr;
	if (nbr < 0)
		lnbr = -nbr;
	str = ft_long_long_to_ascii_base(lnbr, 10);
	str = ft_process_d_precision(str, arg);
	if (nbr < 0)
		str = ft_strjoin("-", str);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	str = ft_process_d_width(str, arg);
	if (arg.flag_plus && nbr >= 0)
		ft_process_d_put_flag_plus(bytes);
	else if (arg.flag_space && nbr >= 0)
		ft_process_d_put_flag_space(bytes);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}

void	ft_process_d_int(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	int		nbr;
	long	lnbr;
	char 	*str;
	
	nbr = va_arg(ap, int);
	lnbr = nbr;
	if (nbr < 0)
		lnbr = -nbr;
	str = ft_long_long_to_ascii_base(lnbr, 10); // make it work for int_to_ascii
	str = ft_process_d_precision(str, arg);
	if (nbr < 0)
		str = ft_strjoin("-", str);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	str = ft_process_d_width(str, arg);
	if (arg.flag_plus && nbr >= 0)
		ft_process_d_put_flag_plus(bytes);
	else if (arg.flag_space && nbr >= 0)
		ft_process_d_put_flag_space(bytes);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}


void	ft_process_d_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{

	if (arg.lm_h)
		ft_process_d_short(ap, bytes, descriptor, arg);
	else if (arg.lm_hh)
		ft_process_c_(ap, bytes, descriptor, arg);
	else if (arg.lm_l)
		ft_process_dd_(ap, bytes, arg);
	else if (arg.lm_ll)
		ft_process_d_long_long(ap, bytes, descriptor, arg);
	else if (arg.lm_j)
		ft_process_d_intmax_t(ap, bytes, descriptor, arg);
	else if (arg.lm_z)
		ft_process_d_ssize_t(ap, bytes, descriptor, arg);
	else
		ft_process_d_int(ap, bytes, descriptor, arg);

}
