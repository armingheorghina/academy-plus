/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_route_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:19:08 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/20 22:44:42 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_smallest_is_first(int *l_a)
{
	int i;
	int small;

	i = 0;
	small = l_a[0];
	while (i < g_aitems)
	{
		if (l_a[i] < small)
			small = l_a[i];
		i++;
	}
	if (l_a[0] == small)
		return (1);
	return (0);
}

int		ft_find_biggest_number(int *l_a)
{
	int i;
	int big;

	i = 0;
	big = l_a[i];
	while (i < g_aitems)
	{
		if (l_a[i] > big)
			big = l_a[i];
		i++;
	}
	return (big);
}

int		ft_l_a_contains_small_and_big_at_start_and_rest_is_sorted(int *l_a)
{
	int i;
	int small;
	int big;

	i = 2;
	small = ft_find_smallest_number(l_a);
	big = ft_find_biggest_number(l_a);
	if (l_a[0] != small)
		return (0);
	if (l_a[1] != big)
		return (0);
	while (i < g_aitems - 1)
	{
		if (l_a[i] > l_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_execute_route_1(int *l_a, t_pslist **ops, int *l_b)
{
	while (!ft_smallest_is_first(l_a))
	{
		ft_rotate_last_to_start(l_a);
		ft_add_to_list(ops, 9);
	}
	if (!ft_l_a_is_sorted(l_a))
	{
		if (ft_l_a_contains_small_and_big_at_start_and_rest_is_sorted(l_a))
		{
			ft_swap(l_a);
			ft_add_to_list(ops, 1);
			ft_rotate_first_to_end(l_a);
			ft_add_to_list(ops, 6);
		}
		else
		{
			ft_pushb(l_b, l_a);
			ft_add_to_list(ops, 5);
		}
	}
}
