/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 20:38:05 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/21 20:50:00 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *restrict dst, const char *restrict src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		while (src[i] && i < n)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
