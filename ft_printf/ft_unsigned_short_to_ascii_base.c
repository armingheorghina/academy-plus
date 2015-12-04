/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_short_to_ascii_base.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:28:49 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/04 17:31:06 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unsigned_short_to_ascii_base(unsigned short val, int base)
{
	static char	buf[32] = "0";
	int		i;

	i = 30;
	if (val == 0)
		return (buf);
	while (val > 0 && i > 0)
	{
		buf[i] = "0123456789abcdef"[val % base];
		val = val / base;
		--i;
	}
	return (buf + i + 1);
}
