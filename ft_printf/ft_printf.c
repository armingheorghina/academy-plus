/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:53:31 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/16 10:18:34 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_chose_identifier2(char *descriptor, va_list ap,
		int *bytes, t_arg arg)
{
	int descriptor_len;

	descriptor_len = ft_strlen(descriptor);
	if (descriptor[descriptor_len - 1] == 'U')
		ft_process_uu_(ap, bytes, descriptor, arg);
	else if (descriptor[descriptor_len - 1] == 'x')
		ft_process_x_(ap, bytes, descriptor, arg);
	else if (descriptor[descriptor_len - 1] == 'X')
		ft_process_xx_(ap, bytes, descriptor, arg);
	else if (descriptor[descriptor_len - 1] == 'c')
		ft_process_c_(ap, bytes, descriptor, arg);
	else if (descriptor[descriptor_len - 1] == 'C')
		ft_process_cc_(ap, bytes);
	else if (descriptor[descriptor_len - 1] == 'f' ||
			descriptor[descriptor_len - 1] == 'F')
		ft_process_f_(ap, bytes, descriptor, arg);
	else if (descriptor[descriptor_len - 1] == '%')
		ft_process_percent_(bytes, arg);
	else
		ft_process_non_valid_conversion_(bytes, descriptor, arg);
}

void	ft_chose_identifier(char *descriptor, va_list ap, int descriptor_len,
		int *bytes)
{
	t_arg	arg;

	ft_initialize_flags_and_lm(&arg);
	ft_verify_flags(&arg, descriptor, ap);
	ft_verify_length_modifiers(&arg, descriptor);
	if (descriptor[descriptor_len - 1] == 's')
		ft_process_s_(ap, bytes, descriptor, arg);
	else if (descriptor[descriptor_len - 1] == 'S')
		ft_process_ss_(ap, bytes, descriptor, arg);
	else if (descriptor[descriptor_len - 1] == 'p')
		ft_process_p_(ap, bytes, descriptor, arg);
	else if (descriptor[descriptor_len - 1] == 'd' ||
			descriptor[descriptor_len - 1] == 'i')
		ft_process_d_(ap, bytes, descriptor, arg);
	else if (descriptor[descriptor_len - 1] == 'D')
		ft_process_dd_(ap, bytes, descriptor, arg);
	else if (descriptor[descriptor_len - 1] == 'o')
		ft_process_o_(ap, bytes, descriptor, arg);
	else if (descriptor[descriptor_len - 1] == 'O')
		ft_process_oo_(ap, bytes, descriptor, arg);
	else if (descriptor[descriptor_len - 1] == 'u')
		ft_process_u_(ap, bytes, descriptor, arg);
	else
		ft_chose_identifier2(descriptor, ap, bytes, arg);
}

void	ft_process_format_found_percent(const char *format, int *i,
		int *bytes, va_list ap)
{
	char	*descriptor;
	int		descriptor_len;

	if (ft_is_a_valid_descriptor(format + *i))
	{
		descriptor_len = ft_descriptor_len(format + *i);
		descriptor = ft_strsub(format, *i, descriptor_len);
		ft_chose_identifier(descriptor, ap, descriptor_len, bytes);
		*i = *i + descriptor_len;
	}
	else
	{
		*i = *i + 1;
		while (ft_strchr(FLAGS, format[*i]) && format[*i])
			*i = *i + 1;
	}
}

int		ft_process_format(const char *format, va_list ap)
{
	int		bytes;
	int		i;

	bytes = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_process_format_found_percent(format, &i, &bytes, ap);
		else
		{
			ft_putchar(format[i]);
			bytes++;
			i++;
		}
	}
	return (bytes);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		bytes;

	bytes = 0;
	va_start(ap, format);
	bytes = ft_process_format(format, ap);
	va_end(ap);
	return (bytes);
}
