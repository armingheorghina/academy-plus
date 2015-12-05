/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_xx_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:57:22 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/05 15:51:51 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_xx_lm_l(va_list ap, int *bytes, t_arg arg)
{
	unsigned long	 nbr;
	char			*str;

	nbr = va_arg(ap, unsigned long);
	str = ft_itoabbase(nbr, 16);
	if (arg.flag_hash && nbr != 0)
	{
		ft_putstr("0X");
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 2;
	}
	else
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}

void	ft_process_xx_lm_z(va_list ap, int *bytes, t_arg arg)
{
	size_t	 nbr;
	char	*str;

	nbr = va_arg(ap, size_t);
	str = ft_itoabbase(nbr, 16);
	if (arg.flag_hash && nbr != 0)
	{
		ft_putstr("0X");
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 2;
	}
	else
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}

void	ft_process_xx_lm_j(va_list ap, int *bytes, t_arg arg)
{
	uintmax_t	 nbr;
	char		*str;

	nbr = va_arg(ap, uintmax_t);
	str = ft_itoabbase(nbr, 16);
	if (arg.flag_hash && nbr != 0)
	{
		ft_putstr("0X");
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 2;
	}
	else
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}

void	ft_process_xx_lm_ll(va_list ap, int *bytes, t_arg arg)
{
	unsigned long long	nbr;
	char				*str;

	nbr = va_arg(ap, unsigned long long);
	str = ft_itoabbase(nbr, 16);
	if (arg.flag_hash && nbr != 0)
	{
		ft_putstr("0X");
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 2;
	}
	else
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}

void	ft_process_xx_lm_h(va_list ap, int *bytes, t_arg arg)
{
	unsigned short	nbr;
	char			*str;

	nbr = va_arg(ap, unsigned int);
	str = ft_itoabbase(nbr, 16);
	if (arg.flag_hash && nbr != 0)
	{
		ft_putstr("0X");
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 2;
	}
	else
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}

void	ft_process_xx_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	unsigned int 	nbr;
	char			*str;


	if (arg.lm_hh)
		ft_process_c_(ap, bytes, descriptor, arg);
	else if (arg.lm_h)
		ft_process_xx_lm_h(ap, bytes, arg);
	else if (arg.lm_l)
		ft_process_xx_lm_l(ap, bytes, arg);
	else if (arg.lm_ll)
		ft_process_xx_lm_ll(ap, bytes, arg);
	else if (arg.lm_j)
		ft_process_xx_lm_j(ap, bytes, arg);
	else if (arg.lm_z)
		ft_process_xx_lm_z(ap, bytes, arg);
	else
	{
		nbr = va_arg(ap, unsigned int);
		str = ft_itoabbase(nbr, 16);
		if (arg.flag_hash && nbr != 0)
		{
			ft_putstr("0X");
			ft_putstr(str);
			*bytes = *bytes + ft_strlen(str) + 2;
		}
		else
		{
			ft_putstr(str);
			*bytes = *bytes + ft_strlen(str);
		}
	}
}
