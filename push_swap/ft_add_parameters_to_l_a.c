/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_parameters_to_l_a.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:32:25 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/20 21:55:41 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_parameters_to_l_a(int *l_a, int items, char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < items)
	{
		l_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	while (i < items)
	{
		j = i + 1;
		while (j < items)
		{
			if (l_a[i] == l_a[j])
				ft_error_and_exit();
			j++;
		}
		i++;
	}
}
