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

static int		ft_descriptor_len(const char *format)
{
	int i;

	i = 1;
	while (ft_strchr(FLAGS, format[i]) && format[i])
		i++;
	if (ft_strchr(CONVERSIONS, format[i]) && format[i] != '\0')
		return (i + 1);
	else if (format[i] == '\0' || !ft_strchr(CONVERSIONS, format[i]))
		return (i - 1);
	else
		return (i);
}

static char		*ft_chose_identifier(char *descriptor, va_list *ap, int descriptor_len)
{
	char *str;
	
	str = NULL;
	ft_putchar(descriptor[descriptor_len - 1]);
	if (descriptor[descriptor_len - 1] == 's')
		str = va_arg(*ap, char *);
	
	return (str);
}

static int		ft_process_format(const char *format, va_list *ap)
{
	int bytes;
	char *descriptor;
	int	descriptor_len;
	int i;

	bytes = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			descriptor_len = ft_descriptor_len(format + i);

			if (descriptor_len > 0)
			{
				descriptor = ft_strsub(format, i, descriptor_len);
				ft_putstr(ft_chose_identifier(descriptor, ap, descriptor_len));
				bytes = bytes + ft_strlen(ft_chose_identifier(descriptor, ap, descriptor_len));
				i = i + descriptor_len;
			}
			else
				i++;
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
	int		bytes;

	bytes = 0;
	va_start(ap, format);
	bytes = ft_process_format(format, &ap);
	va_end(ap);
	return (bytes);
}
