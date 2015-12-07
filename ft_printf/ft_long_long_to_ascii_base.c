/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_long_to_ascii_base.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:28:24 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/07 15:12:43 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_long_long_to_ascii_base(long long val, int base)
{
	static char		buf[32] = "0";
	int			i;
	unsigned long long 	val2;	

	i = 30;
	if (val == 0)
		return (ft_strdup("0"));
	if (val < 0)
	{
		val2 = -val;
		while (val2 > 0 && i > 0)
		{
			buf[i--] = "0123456789abcdef"[val2 % base];
			val2 = val2 / base;
		}
		buf[i] = '-';
		return (buf + i + 1);
	}
	while (val > 0 && i > 0)
	{
		buf[i--] = "0123456789abcdef"[val % base];
		val = val / base;
	}
	return (buf + i + 1);
}
