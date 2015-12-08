/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:20:21 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/08 13:04:23 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_d_precision(char *str, t_arg arg)
{
	char *str0;
	if (arg.precision > ft_strlen(str))
	{
		str0 = ft_memalloc(arg.precision - ft_strlen(str) + 1);
		str0 = ft_memset(str0, '0', arg.precision - ft_strlen(str));
		str = ft_strjoin(str0, str);
	}
	return (str);
}
