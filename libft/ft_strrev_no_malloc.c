/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev_no_malloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 21:47:04 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/24 22:08:04 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev_no_malloc(char *s)
{
	char	tmp;
	int		i;
	int		len;

	len = 0;
	while (s[len])
		len++;
	i = 0;
	len--;
	while (i < len)
	{
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
		i++;
		len--;
	}
	//		s[len] = '\0';
	return (s);
}
