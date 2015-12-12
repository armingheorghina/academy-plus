/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_p_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:18:55 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/12 15:45:01 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_p_width(char *str, t_arg arg)
{
	char *strp;

	if (arg.flag_minus)
	{
		if (arg.width > ft_strlen(str))
		{
			strp = ft_memalloc(arg.width - ft_strlen(str) + 1);
			strp = ft_memset(strp, ' ', arg.width - ft_strlen(str));
			str = ft_strjoin(str, strp);
		}
	}
	else if (arg.flag_zero)
	{
		if (arg.width > ft_strlen(str))
		{
			strp = ft_memalloc(arg.width - ft_strlen(str) + 1);
			strp = ft_memset(strp, '0', arg.width - ft_strlen(str));
			str = ft_strjoin(str, strp);
		}
	}
	if (arg.width > ft_strlen(str))
	{
		strp = ft_memalloc(arg.width - ft_strlen(str) + 1);
		strp = ft_memset(strp, ' ', arg.width - ft_strlen(str));
		str = ft_strjoin(strp, str);
	}
	return (str);
}

void	ft_process_p_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	void	*voidp;
	char	*str;

	voidp = va_arg(ap, void *);
	str = ft_unsigned_long_to_ascii_base((unsigned long)voidp, 16);
	str = ft_process_d_precision(str, arg);
	if (arg.precision == 0 && ft_atoi(str) == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	str = ft_strjoin("0x", str);
	str = ft_process_p_width(str, arg);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}
