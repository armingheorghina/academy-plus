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

void		ft_process_ss_precision(wchar_t **wstr, t_arg arg)
{
	*wstr = ft_wstrsub(*wstr, 0, arg.precision);
}

wchar_t		*ft_process_ss_width(wchar_t *wstr, t_arg arg)
{
	wchar_t *strp;
	int i;

	i = 0;
	while (wstr[i])
		i++;
	if (arg.width > i)
	{
		strp = (wchar_t*)malloc(sizeof(*strp) * (arg.width - i + 1));
		strp[arg.width - i] = '\0';
		strp = ft_wmemset(strp, L' ', arg.width - i);
		wstr = ft_wstrjoin(strp, wstr);
	}
	return (wstr);
}

void	ft_process_ss_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	wchar_t *wstr;
	int i;

	i = 0;
	wstr = va_arg(ap, wchar_t *);
	if (wstr)
	{
		if (arg.precision)
			ft_process_ss_precision(&wstr, arg);
		if (arg.precision == 0 && ft_strchr(descriptor, '.'))
			wstr = ft_wstrdup(L"");
		if (arg.width)
			wstr = ft_process_ss_width(wstr, arg);
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
