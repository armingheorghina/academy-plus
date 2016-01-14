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

void	ft_execute_route_1(int *l_a, int *aitems, int *l_b, int *bitems,
		t_pslist **ops)
{
	int o;

	o = 3;
	while (!ft_smallest_is_first(l_a, aitems)) //TODO in this file
	{
		
		ft_rotate_last_to_start(l_a, aitems);
		ft_add_to_list(l_a, aitems, ops, o); // TODO correct the other file
	}
}
