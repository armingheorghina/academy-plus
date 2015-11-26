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

	va_start(ap, format);
	while ((st = ft_strchr(format, 's')) != NULL)
	{	
		s = va_arg(ap, char *);
		ft_putendl(s);
		format = ft_strdup(st + 1);
	}
	va_end(ap);
	return (0);
}
