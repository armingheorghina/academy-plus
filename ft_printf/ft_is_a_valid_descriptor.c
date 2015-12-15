/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_a_valid_descriptor.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 19:50:06 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/15 19:52:00 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_a_valid_descriptor(const char *str)
{
	int i;

	i = 1;
	while (ft_strchr(FLAGS, str[i]) && str[i])
		i++;
	if (ft_strchr(CONVERSIONS, str[i]) && str[i])
		return (1);
	else if ((str[i] == '%') && str[i])
		return (1);
	else if (ft_isalpha(str[i]) && str[i])
		return (1);
	return (0);
}
