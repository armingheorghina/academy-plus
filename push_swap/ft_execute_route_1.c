/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_route_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:19:08 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/14 16:10:54 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_smallest_is_first(int *l_a, int aitems)
{
	int i;
	int small;

	i = 0;
	small = l_a[0];
	while (i < aitems)
	{
		if (l_a[i] < small)
			small = l_a[i];
		i++;
	}
	if (l_a[0] == small)
		return (1);
	return (0);
}

void	ft_execute_route_1(int *l_a, int aitems, t_pslist **ops)
{
	int o;

	o = 9;
	while (!ft_smallest_is_first(l_a, aitems))
	{
		ft_rotate_last_to_start(l_a, aitems);
		ft_add_to_list(ops, o);
	}
}
