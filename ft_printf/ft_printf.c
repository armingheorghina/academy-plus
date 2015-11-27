/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:53:31 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/26 18:18:24 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list ap;
	char *s;
	char *st;
	int	i;

	
	va_start(ap, format);
	while ((st = ft_strchr(format, 's')) != NULL)
	{	
		s = va_arg(ap, char *);
		ft_putstr(s);
		format = ft_strdup(st + 1);
		i = 0;
		while (format[i])
		{
			if (ft_strcmp(ft_strjoin("format[i]", "format[i + 1]"), "%%") == 0)
				i = i + 2;;
			if (format[i] == '%' && format[i + 1] == 's') // ft_strcmp(ft_strjoin("format[i]", "format[i + 1]"), "%%") == 0)
				break;
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (0);
}
