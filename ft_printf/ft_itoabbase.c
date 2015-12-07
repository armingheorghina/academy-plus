/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:48:13 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/07 18:43:28 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoabbase(uintmax_t val, int base)
{
	static char	buf[32] = "0";
	int		i;

	i = 30;
	if (val == 0)
		return (ft_strdup("0"));
	while (val > 0 && i > 0)
	{
		buf[i] = "0123456789ABCDEF"[val % base];
		val = val / base;
		--i;
	}
	return (buf + i + 1);
}
