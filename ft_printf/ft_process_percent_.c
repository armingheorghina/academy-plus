/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_percent_.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:58:03 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/12 16:25:06 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	ft_process_percent_width(char **str, t_arg arg)
{
	char *strp;

	if (arg.width > ft_strlen(*str))
	{
		if (arg.flag_minus)
		{
			strp = ft_memalloc(arg.width - ft_strlen(*str) + 1);
			strp = ft_memset(strp, ' ', arg.width - ft_strlen(*str));
			*str = ft_strjoin(*str, strp);
		}
		else if (arg.flag_zero)
		{
			strp = ft_memalloc(arg.width - ft_strlen(*str) + 1);
			strp = ft_memset(strp, '0', arg.width - ft_strlen(*str));
			*str = ft_strjoin(strp, *str);
		}
		else
		{
			strp = ft_memalloc(arg.width - ft_strlen(*str) + 1);
			strp = ft_memset(strp, ' ', arg.width - ft_strlen(*str));
			*str = ft_strjoin(strp, *str);
		}
	}
}

void	ft_process_percent_(int *bytes, t_arg arg)
{
	char *str;

	str = ft_strdup("%");
	ft_process_percent_width(&str, arg);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}
