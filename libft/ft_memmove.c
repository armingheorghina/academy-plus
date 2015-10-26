/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 18:00:01 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/26 15:15:22 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (void*)malloc(len);
	while (i < len)
	{
		*(tmp + i) = *(unsigned char*)(src + i);
		i++;
	}
	i = 0;
	while (i < len)
	{
		*(unsigned char*)(dst + i) = *(tmp + i);
		i++;
	}
	free(tmp);
	return (dst);
}
