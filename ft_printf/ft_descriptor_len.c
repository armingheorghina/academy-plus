/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_descriptor_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 19:53:24 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/15 19:54:05 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_descriptor_len(const char *format)
{
	int i;

	i = 1;
	while (ft_strchr(FLAGS, format[i]) && format[i])
		i++;
	if (ft_strchr(CONVERSIONS, format[i]) && format[i])
		return (i + 1);
	else if ((format[i] == '%') && format[i])
		return (i + 1);
	else if (ft_isalpha(format[i]) && format[i])
		return (i + 1);
	return (i);
}
