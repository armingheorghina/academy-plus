/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_long_to_ascii_base.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:28:24 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/04 18:47:17 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_long_long_to_ascii_base(long long val, int base)
{
	static char	buf[32] = "0";
	int		i;
	int		ok;

	i = 30;
	ok = 0;
	if (val == -9223372036854775807 - 1 && base == 10)
		return ("-9223372036854775808");
	if (val == 0)
		return (buf);
	if (val < 0)
	{
		val = -val;
		ok = 1;
	}
	while (val > 0 && i > 0)
	{
		buf[i] = "0123456789abcdef"[val % base];
		val = val / base;
		--i;
	}
	if (ok == 1)
	{
		buf[i] = '-';
		return (buf + i);
	}
	return (buf + i + 1);
}
