/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_parameters_to_l_a.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:32:25 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/19 16:58:21 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_parameters_to_l_a(int *l_a, int items, char **argv)
{
	int i;

	i = 0;
	while (i < items)
	{
		l_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}
