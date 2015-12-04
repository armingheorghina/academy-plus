/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_p_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:18:55 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/04 12:58:49 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_p_(va_list ap, int *bytes)
{
	void	*voidp;
	char	*str;

	voidp = va_arg(ap, void *);
	str = ft_itoabase((unsigned long)voidp, 16);
	str = ft_strjoin("0x", str);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}
