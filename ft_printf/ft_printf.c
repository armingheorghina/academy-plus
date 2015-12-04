/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:53:31 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/04 15:23:19 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_is_a_valid_descriptor(const char *str)
{
	int i;

	i = 1;
	while (ft_strchr(FLAGS, str[i]) && str[i])
		i++;
	if (ft_strchr(CONVERSIONS, str[i]) && str[i])
		return (1);
	else if ((str[i] == '%') && str[i])
		return (1);
	return (0);
}

static int		ft_descriptor_len(const char *format)
{
	int i;

	i = 1;
	while (ft_strchr(FLAGS, format[i]) && format[i])
		i++;
	if (ft_strchr(CONVERSIONS, format[i]) && format[i])
		return (i + 1);
	else if ((format[i] == '%') && format[i])
		return (i + 1);
	return (i);
}


void	ft_initialize_flags_and_lm(t_arg *arg)
{
		arg->flag_hash = 0;
        arg->flag_zero = 0;
        arg->flag_minus = 0;
        arg->flag_plus = 0;
        arg->flag_space = 0;
        arg->lm_j = 0;
        arg->lm_z = 0;
        arg->lm_h = 0;
        arg->lm_hh = 0;
        arg->lm_l = 0;
        arg->lm_ll = 0;
}

void	ft_verify_flags(t_arg *arg, char *descriptor)
{
	int i;

	i = 0;
	while (descriptor[i])
	{
		if (descriptor[i] == '#')
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

void	ft_verify_length_modifiers(t_arg *arg, char *descriptor)
{
	int i;

	i = 0;
	while (descriptor[i])
	{
		if (descriptor[i] == 'h' && descriptor[i + 1] == 'h')
		{
			arg->lm_hh = 1;
			i++;
		}
		else if (descriptor[i] == 'h')
			arg->lm_h = 1;
		else if (descriptor[i] == 'l' && descriptor[i + 1] == 'l')
		{
			arg->lm_ll = 1;
			i++;
		}
		else if (descriptor[i] == 'l')
			arg->lm_l = 1;
		else if (descriptor[i] == 'j')
			arg->lm_j = 1;
		else if (descriptor[i] == 'z')
			arg->lm_z = 1;
		i++;
	}
}

static void		ft_chose_identifier(char *descriptor, va_list ap, int descriptor_len, int *bytes)
{
	t_arg	arg;

	ft_initialize_flags_and_lm(&arg);
	ft_verify_flags(&arg, descriptor);
	ft_verify_length_modifiers(&arg, descriptor);
	if (descriptor[descriptor_len - 1] == 's')
		ft_process_s_(ap, bytes, arg);
	if (descriptor[descriptor_len - 1] == 'S')
		ft_process_ss_(ap, bytes);
	if (descriptor[descriptor_len - 1] == 'p')
		ft_process_p_(ap, bytes);
	if (descriptor[descriptor_len - 1] == 'd' || descriptor[descriptor_len - 1] == 'i')
		ft_process_d_(ap, bytes, descriptor, arg);
	if (descriptor[descriptor_len - 1] == 'D')
		ft_process_dd_(ap, bytes, arg);
	if (descriptor[descriptor_len - 1] == 'o')
		ft_process_o_(ap, bytes, descriptor, arg);
	if (descriptor[descriptor_len - 1] == 'O')
		ft_process_oo_(ap, bytes, arg);
	if (descriptor[descriptor_len - 1] == 'u')
		ft_process_u_(ap, bytes, descriptor, arg);
	if (descriptor[descriptor_len - 1] == 'U')
		ft_process_uu_(ap, bytes);
	if (descriptor[descriptor_len - 1] == 'x')
		ft_process_x_(ap, bytes, descriptor, arg);
	if (descriptor[descriptor_len - 1] == 'X')
		ft_process_xx_(ap, bytes, descriptor, arg);

	if (descriptor[descriptor_len - 1] == 'c')
		ft_process_c_(ap, bytes, descriptor, arg);
	if (descriptor[descriptor_len - 1] == 'C')
		ft_process_cc_(ap, bytes);



}

static int		ft_process_format(const char *format, va_list ap)
{
	int		bytes;
	char	*descriptor;
	int		descriptor_len;
	int		i;

	bytes = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_is_a_valid_descriptor(format + i))
			{
				descriptor_len = ft_descriptor_len(format + i);
				if (format[i + descriptor_len - 1] == '%') //TODO ce se intampla cand intre %...% exista flaguri?
				{
					ft_putchar('%');
					bytes++;
					i = i + descriptor_len;
				}
				else
				{
					descriptor = ft_strsub(format, i, descriptor_len);
					ft_chose_identifier(descriptor, ap, descriptor_len, &bytes);
					i = i + descriptor_len;
				}
			}
			else
			{
				i++;
				while (ft_strchr(FLAGS, format[i]) && format[i])
					i++;
			}
		}
		else
		{
			ft_putchar(format[i]);
			bytes++;
			i++;
		}
	}
	return (bytes);
}

int				ft_printf(const char *format, ...)
{
	va_list ap;
	int	bytes;

	bytes = 0;
	va_start(ap, format);
	bytes = ft_process_format(format, ap);
	va_end(ap);
	return (bytes);
}
