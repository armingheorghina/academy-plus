/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_cc_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:01:40 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/02 13:02:19 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_process_cc_(va_list ap, int *bytes)
{
	wchar_t wc;

	wc = va_arg(ap, wchar_t);
	ft_putwchar(wc);
	*bytes += ft_wcharsize(wc);
}
