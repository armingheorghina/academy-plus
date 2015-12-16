/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 10:04:53 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/16 10:28:47 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_verify_flags_width(t_arg *arg, char *descriptor, int *i)
{
	int j;

	arg->width = ft_atoi(descriptor + *i);
	j = ft_strlen(ft_itoa(arg->width));
	while (j > 1)
	{
		j--;
		(*i)++;
	}
}

void	ft_verify_flags_precision(t_arg *arg, char *descriptor, int *i)
{
	arg->precision = ft_atoi(descriptor + *i + 1);
	while (ft_isdigit(descriptor[*i + 1]))
		(*i)++;
}

void	ft_verify_flags_precision_asterix(t_arg *arg, char *descriptor,
		va_list ap)
{
	arg->precision = va_arg(ap, int);
	if (arg->precision < 0 && descriptor[ft_strlen(descriptor) - 1] == 's')
	{
		arg->precision = -1 * arg->precision;
	}
	else if (arg->precision < 0)
		arg->precision = 0;
}

void	ft_verify_flags_width_asterix(t_arg *arg, va_list ap)
{
	arg->width = va_arg(ap, int);
	if (arg->width < 0)
	{
		arg->width = -1 * arg->width;
		arg->flag_minus = 1;
	}
}

void	ft_verify_flags(t_arg *arg, char *descriptor, va_list ap)
{
	int i;

	i = 0;
	while (descriptor[i])
	{
		if (ft_isdigit(descriptor[i]) && descriptor[i] != '0')
			ft_verify_flags_width(arg, descriptor, &i);
		else if (descriptor[i] == '.')
			ft_verify_flags_precision(arg, descriptor, &i);
		else if (descriptor[i] == '*' && descriptor[i - 1] == '.')
			ft_verify_flags_precision_asterix(arg, descriptor, ap);
		else if (descriptor[i] == '*' && descriptor[i - 1] != '.')
			ft_verify_flags_width_asterix(arg, ap);
		else if (descriptor[i] == '#')
			arg->flag_hash = 1;
		else if (descriptor[i] == '0')
			arg->flag_zero = 1;
		else if (descriptor[i] == '-')
			arg->flag_minus = 1;
		else if (descriptor[i] == '+')
			arg->flag_plus = 1;
		else if (descriptor[i] == ' ')
			arg->flag_space = 1;
		i++;
	}
}
