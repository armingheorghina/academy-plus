/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 14:57:25 by vdruta            #+#    #+#             */
/*   Updated: 2015/09/24 21:15:31 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_find_number(char *str)
{
	char	*str2;
	int		i;

	str2 = ft_find_str_number(str);
	i = 0;
	while (str2[i] != '\0')
	{
		if (!(str2[i] >= '0' && str2[i] <= '9'))
			return (0);
		i++;
	}
	return (ft_atoi(ft_find_str_number(str)));
}
