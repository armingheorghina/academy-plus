/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:02:56 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/04 15:11:19 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_d_put_flag_plus(char *str, int *bytes)
{
	ft_putchar('+');
	ft_putstr(str);
	*bytes += ft_strlen(str) + 1;
}

void	ft_process_d_put_flag_space(char *str, int *bytes)
{
	ft_putchar(' ');
	ft_putstr(str);
	*bytes += ft_strlen(str) + 1;
}

void	ft_process_d_intmax_t(va_list ap, int *bytes, t_arg arg)
{
	intmax_t	nbr;
	char	 	*str;

	nbr = va_arg(ap, intmax_t);
	str = ft_intmax_t_to_ascii_base(nbr, 10);
	if (arg.flag_plus && nbr >= 0)
		ft_process_d_put_flag_plus(str, bytes);
	else if (arg.flag_space && nbr >= 0)
		ft_process_d_put_flag_space(str, bytes);
	else
	{
		ft_putstr(str);
		*bytes += ft_strlen(str);
	}
}

void	ft_process_d_size_t(va_list ap, int *bytes, t_arg arg)
{
	size_t	nbr;
	char 	*str;

	nbr = va_arg(ap, size_t);
	str = ft_intmax_t_to_ascii_base(nbr, 10);
	if (arg.flag_plus)// && nbr >= 0)
		ft_process_d_put_flag_plus(str, bytes);
	else if (arg.flag_space)// && nbr >= 0)
		ft_process_d_put_flag_space(str, bytes);
	else
	{
		ft_putstr(str);
		*bytes += ft_strlen(str);
	}
}


void	ft_process_d_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	int		nbr;
	char 	*str;

	if (arg.lm_hh)
		ft_process_c_(ap, bytes, descriptor, arg);
	else if (arg.lm_l)
		ft_process_dd_(ap, bytes, arg);
	else if (arg.lm_j)
		ft_process_d_intmax_t(ap, bytes, arg);
	else if (arg.lm_z)
		ft_process_d_size_t(ap, bytes, arg);
	else
	{
		nbr = va_arg(ap, int);
		str = ft_intmax_t_to_ascii_base(nbr, 10);
		if (arg.flag_plus && nbr >= 0)
			ft_process_d_put_flag_plus(str, bytes);
		else if (arg.flag_space && nbr >= 0)
			ft_process_d_put_flag_space(str, bytes);
		else
		{
			ft_putstr(str);
			*bytes += ft_strlen(str);
		}
	}
}
