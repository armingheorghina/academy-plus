/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_non_valid_conversion_.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:43:42 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/14 18:26:35 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_non_valid_conversion_(int *bytes, char *descriptor,
		t_arg arg)
{
	char	*str;
	int		len;

	len = ft_strlen(descriptor);
	str = (char *)malloc(sizeof(*str) + 1);
	str[0] = descriptor[len - 1];
	str[1] = '\0';
	ft_process_percent_width(&str, arg);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}
