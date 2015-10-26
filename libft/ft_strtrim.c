/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 20:13:20 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/24 21:48:23 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_rev(char const *s)
{
	char	*rev;
	int		i;
	int		j;

	rev = (char*)malloc(sizeof(rev) * (ft_strlen(s) + 1));
	i = 0;
	while (s[i])
		i++;
	i--;
	j = 0;
	while (i >= 0)
	{
		rev[j] = s[i];
		j++;
		i--;
	}
	rev[j] = '\0';
	return (rev);
}

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*dst;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	dst = (char*)malloc(sizeof(dst) * (ft_strlen(s + i) + 1));
	dst = ft_str_rev(s + i);
	i = 0;
	while (dst[i] == ' ' || dst[i] == '\n' || dst[i] == '\t')
		i++;
	return (ft_str_rev(dst + i));
}
