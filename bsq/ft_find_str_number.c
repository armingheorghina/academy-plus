/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_str_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 14:36:59 by vdruta            #+#    #+#             */
/*   Updated: 2015/09/24 22:30:29 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_find_str_number(char *str)
{
	int		i;
	int		k;
	char	*dest;

	i = 0;
	k = (ft_line_lenght(str) - 3);
	dest = (char*)malloc(sizeof(dest) * (k + 1));
	while (str[i] != str[k])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
