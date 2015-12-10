/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_p_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:18:55 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/10 12:53:12 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// TODO do it man!!
void	ft_process_p_(va_list ap, int *bytes)
{
	void	*voidp;
	char	*str;

	voidp = va_arg(ap, void *);
	str = ft_itoabase((unsigned long)voidp, 16);
		if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
			str[0] = '\0';
		str = ft_process_d_width(str, arg);
		if (arg.flag_hash && nbr != 0)
		{
			ft_putstr("0x");
			ft_putstr(str);
			*bytes = *bytes + ft_strlen(str) + 2;
		}
		else
		{
			ft_putstr(str);
			*bytes = *bytes + ft_strlen(str);
		}
//	str = ft_strjoin("0x", str);
//	ft_putstr(str);
//	*bytes += ft_strlen(str);
}
