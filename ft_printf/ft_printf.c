/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:53:31 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/28 17:27:23 by vdruta           ###   ########.fr       */
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

static void		ft_chose_identifier(char *descriptor, va_list ap, int descriptor_len, int *bytes)
{
	if (descriptor[descriptor_len - 1] == 's')
		ft_process_s_(ap, bytes);
//	if (descriptor[descriptor_len - 1] == 'S')
//		ft_process_S_(ap, bytes);
	if (descriptor[descriptor_len - 1] == 'p')
		ft_process_p_(ap, bytes);
	if (descriptor[descriptor_len - 1] == 'd' || descriptor[descriptor_len - 1] == 'i')
		ft_process_d_(ap, bytes);
	if (descriptor[descriptor_len - 1] == 'o')
		ft_process_o_(ap, bytes);
	if (descriptor[descriptor_len - 1] == 'u')
		ft_process_u_(ap, bytes);
	if (descriptor[descriptor_len - 1] == 'x')
		ft_process_x_(ap, bytes);
	if (descriptor[descriptor_len - 1] == 'X')
		ft_process_X_(ap, bytes);
//	if (descriptor[descriptor_len - 1] == 'D')
//		ft_process_D_(ap, bytes);
	if (descriptor[descriptor_len - 1] == 'c')
		ft_process_c_(ap, bytes);

//OUC


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
				if (format[i + descriptor_len - 1] == '%')
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
	int	bytes;

	bytes = 0;
	va_start(ap, format);
	bytes = ft_process_format(format, ap);
	va_end(ap);
	return (bytes);
}
