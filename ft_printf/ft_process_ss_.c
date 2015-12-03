/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_ss_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:51:53 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/03 18:35:07 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_ss_(va_list ap, int *bytes)
{
	wchar_t *wstr;
	int i;

	i = 0;
	wstr = va_arg(ap, wchar_t *);
	if (wstr)
	{
		while (wstr[i])
		{
			ft_putwchar(wstr[i]);
			*bytes += ft_wcharsize(wstr[i]);
			i++;
		}
	}
	else
	{
		ft_putstr("(null)");
		*bytes += 6;
	}
}
