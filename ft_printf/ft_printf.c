/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:53:31 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/27 17:09:23 by vdruta           ###   ########.fr       */
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
	return (i);
}

static char		*ft_chose_identifier(char *descriptor, va_list ap, int descriptor_len)
{
	char *str;

	if (descriptor[descriptor_len - 1] == 's')
		str = va_arg(ap, char *);
	if (descriptor[descriptor_len - 1] == 'd')
		str = ft_itoa(va_arg(ap, int));
	
	
	return (str);
}

static int		ft_process_format(const char *format, va_list ap)
{
	int	bytes;
	char	*descriptor;
	int	descriptor_len;
	int	i;
	char 	*to_print;

	bytes = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar('%');
			bytes++;
			i = i + 2;
		}
		else if (format[i] == '%')
		{

			if (!ft_is_a_valid_descriptor(format + i))
				i = i + 1;
			else
			{
				descriptor_len = ft_descriptor_len(format + i);
				descriptor = ft_strsub(format, i, descriptor_len);
				to_print = ft_chose_identifier(descriptor, ap, descriptor_len);
				ft_putstr(to_print);
				bytes = bytes + ft_strlen(to_print);
				i = i + descriptor_len;
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
