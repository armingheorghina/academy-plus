/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:48:04 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/20 18:40:27 by vdruta           ###   ########.fr       */
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
		else
			break;
		i++;
	}
	free(sorted);
	if (ok > aitems - ok)
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

int		ft_count_unsorted(int *l_a, int aitems)
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
		else
			break;
		i++;
	}
	free(sorted);
	return (aitems - ok);
}

int		ft_other_than_first_two_list_is_sorted(int *l_a, int aitems)
{
	int i;

	i = 2;
	while (i < aitems - 1)
	{
		if (l_a[i] > l_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_execute_operations_case_x(int *l_a, int *aitems, t_pslist **ops)
{
	ft_swap(l_a, *aitems);
	ft_add_to_list(ops, 1);
	ft_rotate_first_to_end(l_a, *aitems);
	ft_add_to_list(ops, 6);
	ft_rotate_first_to_end(l_a, *aitems);
	ft_add_to_list(ops, 6);
}

void	ft_execute_operations_case_y(int *l_a, int *aitems, t_pslist **ops, int *l_b, int *bitems)
{
	ft_push(l_a, aitems, l_b, bitems);
	ft_add_to_list(ops, 4);
	ft_rotate_first_to_end(l_a, *aitems);
	ft_add_to_list(ops, 6);
}

void	ft_solve_case_special(int *l_a, int *aitems, t_pslist **ops, int *l_b, int *bitems)
{
	int items;
	int unsorted;
	int count;

	items = *aitems;
	unsorted = ft_count_unsorted(l_a, *aitems);
	count = 0;
	while (!ft_l_a_is_complete_and_sorted(l_a, *aitems, items))
	{
		while (!ft_l_a_is_sorted(l_a, *aitems))
		{
			while (!ft_biggest_is_first(l_a, *aitems))
			{
				ft_rotate_last_to_start(l_a, *aitems);
				ft_add_to_list(ops, 9);
				count++;
			}
			if (unsorted == count && l_a[0] > l_a[1] && ft_other_than_first_two_list_is_sorted(l_a, *aitems))
				ft_execute_operations_case_x(l_a, aitems, ops);
			else
			{
				ft_push(l_b, bitems, l_a, aitems);
				ft_add_to_list(ops, 5);
				count--;
				unsorted--;
			}
		}
		if (!ft_l_a_is_complete_and_sorted(l_a, *aitems, items))
			ft_execute_operations_case_y(l_a, aitems, ops, l_b, bitems);
	}
}
