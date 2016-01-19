/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:48:04 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/19 16:56:28 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_nbr_of_sorted_is_bigger_than_unsorted(int *l_a, int aitems)
{
	int i;
	int ok;
	int *sorted;

	i = 0;
	ok = 0;
	sorted = ft_bubble_sort(l_a, aitems);
	while (i < aitems)
	{
		if (l_a[i] == sorted[i])
			ok++;
		i++;
	}
	if (ok > i - ok)
		return (1);
	return (0);
}

int		ft_biggest_is_first(int *l_a, int aitems)
{
	int big;
	int i;

	i = 0;
	big = l_a[0];
	while (i < aitems)
	{
		if (l_a[i] > big)
			big = l_a[i];
		i++;
	}
	if (l_a[0] == big)
		return (1);
	return (0);
}

void	ft_solve_case_special(int *l_a, int *aitems, t_pslist **ops, int *l_b, int *bitems)
{
	int items;

	items = *aitems;
	while (!ft_l_a_is_complete_and_sorted(l_a, *aitems, items))
	{
		while (!ft_l_a_is_sorted(l_a, *aitems))
		{
			while (!ft_biggest_is_first(l_a, *aitems))
			{
				ft_rotate_last_to_start(l_a, *aitems);
				ft_add_to_list(ops, 9);
			}
			ft_swap(l_a, *aitems);
			ft_add_to_list(ops, 1);
			ft_rotate_first_to_end(l_a, *aitems);
			ft_add_to_list(ops, 6);
			ft_rotate_first_to_end(l_a, *aitems);
			ft_add_to_list(ops, 6);
		}

	}
	(*bitems)++;
	l_b[0] = 1;


	/*
	   ft_rotate_last_to_start(l_a, aitems);
	   ft_add_to_list(ops, 9);
	   ft_rotate_last_to_start(l_a, aitems);
	   ft_add_to_list(ops, 9);
	   ft_swap(l_a, aitems);
	   ft_add_to_list(ops, 1);
	   ft_rotate_first_to_end(l_a, aitems);
	   ft_add_to_list(ops, 6);
	   ft_rotate_first_to_end(l_a, aitems);
	   ft_add_to_list(ops, 6);
	   */
}
