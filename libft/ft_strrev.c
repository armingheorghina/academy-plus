/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 20:45:24 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/28 16:57:37 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *s)
{
	char	*rev;
	int 	i;
	int 	j;

	rev = (char*)malloc(sizeof(*rev) * (ft_strlen(s) + 1));
	i = 0;
	while (s[i])
		i++;
	i--;
	j = 0;
	while (i >= 0 )
	{
		rev[j] = s[i];
		j++;
		i--;
	}
	rev[j] = '\0';
	return (rev);
}
