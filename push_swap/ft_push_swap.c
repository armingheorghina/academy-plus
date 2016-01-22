/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:06:41 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/22 14:39:57 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_last_to_startb(int *l_a, t_pslist **ops)
{
	int temp;
	int	i;

	if (g_bitems < 2)
		return ;
	temp = l_a[g_bitems - 1];
	i = g_bitems - 1;
	while (i > 0)
	{
		l_a[i] = l_a[i - 1];
		i--;
	}
	l_a[0] = temp;
	ft_add_to_list(ops, 10);
}

void	ft_rotate_last_to_start(int *l_a, t_pslist **ops)
{
	int temp;
	int	i;

	if (g_aitems < 2)
		return ;
	temp = l_a[g_aitems - 1];
	i = g_aitems - 1;
	while (i > 0)
	{
		l_a[i] = l_a[i - 1];
		i--;
	}
	l_a[0] = temp;
	ft_add_to_list(ops, 9);
}

void	ft_execute_case_3_numbers(int *l_a, t_pslist **ops)
{
	ft_swap(l_a, ops);
	ft_rotate_first_to_end(l_a, ops);
}

void	ft_solve_case_standard(int *l_a, t_pslist **ops, int *l_b)
{
	int route;

	route = ft_find_shortest_route_of_smallest_number(l_a);
	if (route == 1)
		ft_execute_route_1(l_a, ops, l_b);
	else
		ft_execute_route_2(l_a, ops, l_b);
}

void	ft_push_swap(int *l_a, int items, int *l_b, t_pslist **ops)
{
	g_aitems = items;
	if (ft_nbr_of_sorted_is_bigger_than_unsorted(l_a))
		ft_solve_case_special(l_a, ops, l_b, items);
	else if (ft_l_a_is_sorted_decreasing(l_a) && items > 2)
		ft_solve_decreasing_list(l_a, ops, l_b);
	else
	{
		while (!ft_l_a_is_complete_and_sorted(l_a, items))
		{
			while (!ft_l_a_is_sorted(l_a))
			{
				if (g_aitems == 3 && l_a[0] < l_a[1] && l_a[1] > l_a[2] &&
						l_a[0] < l_a[2])
					ft_execute_case_3_numbers(l_a, ops);
				else
					ft_solve_case_standard(l_a, ops, l_b);
			}
			if (!ft_l_a_is_complete_and_sorted(l_a, items))
				ft_push(l_a, l_b, ops);
		}
	}
}
