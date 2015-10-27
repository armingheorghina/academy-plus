/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 20:13:20 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/27 14:27:09 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_str_rev(char const *s)
{
	int		i;
	int		j;
	char	ctmp;

	i = 0;
	while (s[i])
		i++;
	i--;
	j = 0;
	while (j < i)
	{
		ctmp = *(char*)(s +j);
		*(char*)(s + j) = *(char*)(s + i);
		*(char*)(s + i) = ctmp;
		j++;
		i--;
	}
	return ((char*)s);
}

static size_t	ft_strlen_and_rev_for_dst(const char *s)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	tmp = ft_str_rev(s);
	while (tmp[i] == ' ' || tmp[i] == '\n' || tmp[i] == '\t')
		i++;
	j = i;
	while (tmp[i])
		i++;
	i = i - j;
	return (i);
}

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*dst;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	dst = (char*)malloc(sizeof(dst) * (ft_strlen_and_rev_for_dst(s + i) + 1));
	if (!dst)
		return (NULL);
	dst = (char*)(s + i);
	i = 0;
	while (dst[i] == ' ' || dst[i] == '\n' || dst[i] == '\t')
		i++;
	return (ft_str_rev(dst + i));
}
