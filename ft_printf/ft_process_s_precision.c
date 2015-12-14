/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_s_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:20:19 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/14 18:21:07 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_s_precision(char **str, t_arg arg)
{
	if (arg.precision < ft_strlen(*str))
		*str = ft_strsub(*str, 0, arg.precision);
}
