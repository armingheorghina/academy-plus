/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_o_lm_j.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:55:20 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/14 18:56:07 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_o_lm_j(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	uintmax_t	nbr;
	char		*str;

	nbr = va_arg(ap, uintmax_t);
	str = ft_uintmax_t_to_ascii_base(nbr, 8);
	g_nbr = 1;
	str = ft_process_d_precision(str, arg);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
	{
		str[0] = '\0';
		if (arg.flag_hash)
			str = ft_strdup("0");
	}
	if (arg.flag_hash && nbr != 0 && !arg.precision)
		str = ft_strjoin("0", str);
	str = ft_process_d_width(str, arg);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}
