/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:18:41 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/07 17:19:02 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_d_width(char *str, t_arg arg)
{
	char *strp;
	
	if (arg.width > ft_strlen(str))
	{
		strp = ft_memalloc(arg.width - ft_strlen(str) + 1);
		strp = ft_memset(strp, ' ', arg.width - ft_strlen(str));
		str = ft_strjoin(strp, str);
	}
	return (str);
}
