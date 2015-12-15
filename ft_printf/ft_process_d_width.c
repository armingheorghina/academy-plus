/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:18:41 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/15 16:42:13 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_d_width_flag_minus(char **str, char **strp, t_arg arg)
{
	if (arg.width > ft_strlen(*str) && !arg.precision && g_nbr >= 0)
	{
		*strp = ft_memalloc(arg.width - ft_strlen(*str) + 1);
		*strp = ft_memset(*strp, ' ', arg.width - ft_strlen(*str));
		*str = ft_strjoin(*str, *strp);
		if (arg.flag_plus)
			*str[ft_strlen(*str) - 1] = '\0';
	}
	else if (arg.width > ft_strlen(*str) && !arg.precision && g_nbr < 0)
	{
		*strp = ft_memalloc(arg.width - ft_strlen(*str));
		*strp = ft_memset(*strp, ' ', arg.width - ft_strlen(*str) - 1);
		*str = ft_strjoin(*str, *strp);
		if (!arg.precision)
			*str = ft_strjoin("-", *str);
	}
	else if (arg.width > ft_strlen(*str) && arg.precision && arg.width)
	{
		*strp = ft_memalloc(arg.width - ft_strlen(*str) + 1);
		*strp = ft_memset(*strp, ' ', arg.width - ft_strlen(*str));
		*str = ft_strjoin(*str, *strp);
		if (arg.flag_plus && g_nbr > 0)
			*str[ft_strlen(*str) - 1] = '\0';
	}
}

void	ft_process_d_width_flag_zero(char **str, char **strp, t_arg arg)
{
	if (arg.width > ft_strlen(*str) && !arg.precision && g_nbr >= 0)
	{
		*strp = ft_memalloc(arg.width - ft_strlen(*str) + 1);
		*strp = ft_memset(*strp, '0', arg.width - ft_strlen(*str));
		*str = ft_strjoin(*strp, *str);
	}
	else if (arg.width > ft_strlen(*str) && !arg.precision && g_nbr < 0)
	{
		*strp = ft_memalloc(arg.width - ft_strlen(*str));
		*strp = ft_memset(*strp, '0', arg.width - ft_strlen(*str) - 1);
		*str = ft_strjoin(*strp, *str);
		if (!arg.precision)
			*str = ft_strjoin("-", *str);
	}
	else if (arg.width > ft_strlen(*str) && arg.precision && arg.width)
	{
		*strp = ft_memalloc(arg.width - ft_strlen(*str) + 1);
		*strp = ft_memset(*strp, ' ', arg.width - ft_strlen(*str));
		*str = ft_strjoin(*strp, *str);
	}
}

char	*ft_process_d_width(char *str, t_arg arg)
{
	char *strp;

	if (arg.flag_minus)
		ft_process_d_width_flag_minus(&str, &strp, arg);
	else if (arg.flag_zero)
		ft_process_d_width_flag_zero(&str, &strp, arg);
	else if (arg.width > ft_strlen(str) && g_nbr >= 0)
	{
		if (arg.flag_plus)
			str = ft_strjoin("+", str);
		strp = ft_memalloc(arg.width - ft_strlen(str) + 1);
		strp = ft_memset(strp, ' ', arg.width - ft_strlen(str));
		str = ft_strjoin(strp, str);
	}
	else if (arg.width > ft_strlen(str) && g_nbr < 0)
	{
		if (!arg.precision)
			str = ft_strjoin("-", str);
		strp = ft_memalloc(arg.width - ft_strlen(str) + 1);
		strp = ft_memset(strp, ' ', arg.width - ft_strlen(str));
		str = ft_strjoin(strp, str);
	}
	return (str);
}
