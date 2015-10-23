/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 14:32:54 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/23 17:14:12 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_str(char *dst, char *str, int i)
{
	int j;

	j = 0;
	while (j < ft_strlen(str))
	{
		dst[j] = str[i];
		i--;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char    *ft_char_strrev(char c, char *str)
{
	int     i;
	int		j;
	char    *dst;

	dst = (char*)malloc(sizeof(*dst) * (ft_strlen(str) + 1));
	i = 0;
	while (str[i])
		i++;
	j = 1;
	i--;
	if (c == '-')
	{
		dst[0] = c;
		while (j <= ft_strlen(str))
		{
			dst[j] = str[i];
			i--;
			j++;
		}
		dst[j] = '\0';
		return (dst);
	}
	else
		return (ft_str_str(dst, str, i));
}

long	ft_nsize(long nb)
{
	long size;

	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		size = 1;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		size = size + 1;
		nb = nb / 10;
	}
	return (size);
}

char	*ft_nb_is_zero(char *v, int nb)
{
	v[0] = '0';
	v[1] = '\0';
	return (v);
}

char	*ft_itoa(int n)
{
	char	*v;
	char	s;
	int		i;
	long	nb;

	nb = n;
	i = 0;
	v = (char*)malloc(ft_nsize(nb));
	s = '+';
	if (nb < 0)
	{
		nb = -nb;
		s = '-';
	}
	if (nb == 0)
		return (ft_nb_is_zero(v, nb));
	while (nb > 0)
	{
		v[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	v[i] = '\0';
	return (ft_char_strrev(s, v));
}
