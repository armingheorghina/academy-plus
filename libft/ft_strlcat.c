/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 13:16:15 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/22 14:51:04 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	while(dst[i])
		i++;
	j = 0;
	if (size < ft_strlen(dst))
		return (ft_strlen(dst) + size);
	else if (size == ft_strlen(dst))
	{
		return (ft_strlen(dst) + ft_strlen(src));
	}
	else
	{
		while(src[j] && j < size - ft_strlen(dst) - 1)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
		return (ft_strlen(dst) + ft_strlen(src));
	}
}
