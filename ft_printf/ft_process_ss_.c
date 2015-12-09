/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_ss_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:51:53 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/09 17:46:20 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_ss_precision(wchar_t **wstr, t_arg arg)
{
	*wstr = ft_wstrsub(*wstr, 0, arg.precision);
}
/*
void	ft_process_ss_width(wchar_t **wstr, t_arg arg)
{
	wchar_t *strp;

	if (arg.width > ft_strlen(*wstr))
	{
		strp = ft_memalloc(arg.width - ft_strlen(*wstr) + 1);
		strp = ft_memset(strp, ' ', arg.width - ft_strlen(*wstr));
		*wstr = ft_strjoin(strp, *wstr);
	}
}
*/
void	ft_process_ss_(va_list ap, int *bytes, t_arg arg)
{
	wchar_t *wstr;
	int i;

	i = 0;
	wstr = va_arg(ap, wchar_t *);
	if (wstr)
	{
		if (arg.precision)
			ft_process_ss_precision(&wstr, arg);
//		if (arg.precision == 0 && ft_strchr(descriptor, '.'))
//			wstr = ft_strdup("");
	//	if (arg.width)
	//		ft_process_ss_width(&wstr, arg);
		
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
