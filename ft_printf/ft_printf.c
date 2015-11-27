/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:53:31 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/27 14:28:52 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_descriptor_len(const char *format)
{
	int i;

	i = 1;
	while (format[i] && ft_strchr(FLAGS, format[i]) != NULL)
		i++;
	i--;
	if (format[i + 1] == '\0')
		return (i + 1);
	else
		return (i + 1 + 1);
}

static int	ft_process_format(const char *format, va_list *ap)
{
	int bytes;
	char *descriptor;
	int	descriptor_len;
	int i;

	bytes = 0;
	i = 0;
	ap = NULL;
	while (format[i])
	{
		if (format[i] == '%')
		{
			descriptor_len = ft_descriptor_len(format + i);
			descriptor = ft_strsub(format, i, descriptor_len);
			ft_putstr(descriptor);
			i = i + descriptor_len;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
		}
	}

	return (bytes);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		bytes;

	bytes = 0;
	va_start(ap, format);
	bytes = ft_process_format(format, &ap);
	va_end(ap);
	return (bytes);
}
