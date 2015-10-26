/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 13:24:55 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/26 15:05:31 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = NULL;
	if (!(mem = (void*)malloc(size)))
		return (NULL);
	mem = ft_memset(mem, 0, size);
	return (mem);
}
