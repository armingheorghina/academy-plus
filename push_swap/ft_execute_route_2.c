/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_route_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:03:52 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/18 17:04:13 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_second_small_number(int *l_a, int aitems)
{
	int *copy;
	int i;
	int temp;

	copy = (int*)malloc(sizeof(*copy) * (aitems));
	i = 0;
	while (i < aitems)
	{
		copy[i] = l_a[i];
		i++;
	}
	copy = ft_bubble_sort(copy, aitems);
	temp = copy[1];
	free(copy);
	return (temp);
}

int		ft_next_is_in_formation(int *l_a, int *aitems, int next, int small)
{
	int i;
	int temp;
	int temp2;

	i = 0;
	while (i < *aitems)
	{
		if (l_a[i] == next)
			temp = i;
		if (l_a[i] == small)
			temp2 = i;
		i++;
	}
	if (temp < temp2)
		return (1);
	return (0);
}

void	ft_execute_route_2(int *l_a, int *aitems, t_pslist **ops, int *l_b, int *bitems)
{
	int small;
	int next;

	small = ft_find_smallest_number(l_a, *aitems);
	next = ft_find_second_small_number(l_a, *aitems);
	while (!ft_smallest_is_first(l_a, *aitems))
	{
		if (ft_next_is_in_formation(l_a, aitems, next, small))
		{
			if (l_a[0] == next && l_a[1] == small)
			{
				ft_swap(l_a, *aitems);
				ft_add_to_list(ops, 1);
			}
			else
			{
				if (l_a[0] != next)
				{
					ft_rotate_first_to_end(l_a, *aitems);
					ft_add_to_list(ops, 6);
				}
				else
				{
					ft_swap(l_a, *aitems);
					ft_add_to_list(ops, 1);
				}
			}
		}
		else
		{
			ft_rotate_first_to_end(l_a, *aitems);
			ft_add_to_list(ops, 6);
		}
	}
	if (!ft_l_a_is_sorted(l_a, *aitems))
	{
		ft_push(l_b, bitems, l_a, aitems);
		ft_add_to_list(ops, 5);
	}
}
