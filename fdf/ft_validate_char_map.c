/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_char_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:50:42 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/02 17:59:14 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_validate_cmap_line(char *str)
{
	int i;
	int ok;

	i = 0;
	ok = 0;
	while (str[i])
	{
		if (str[i] == '-')
			ok++;
		if (str[i] == ' ')
			ok--;
		i++;
	}
	if (ok > 1)
		ft_error_and_exit();
}

void	ft_validate_char_map(char **cmap)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	i = 0;
	while (cmap[i])
	{
		ft_validate_cmap_line(cmap[i]);
		j = 0;
		tmp = ft_strsplit(cmap[i], ' ');
		while (tmp[j])
		{
			k = 0;
			while (tmp[j][k])
			{
				if (ft_isdigit(tmp[j][k]) || tmp[j][k] == '-')
					k++;
				else
					ft_error_and_exit();
			}
			j++;
		}
		i++;
	}
}
