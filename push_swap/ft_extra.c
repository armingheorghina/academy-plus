/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:48:04 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/20 22:43:56 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_nbr_of_sorted_is_bigger_than_unsorted(int *l_a)
{
	int i;
	int ok;
	int *sorted;

	i = 0;
	ok = 0;
	sorted = ft_bubble_sort(l_a);
	while (i < g_aitems)
	{
		if (l_a[i] == sorted[i])
			ok++;
		else
			break;
		i++;
	}
	free(sorted);
	if (ok > g_aitems - ok)
		return (1);
	return (0);
}

int		ft_biggest_is_first(int *l_a)
{
	int big;
	int i;

	i = 0;
	big = l_a[0];
	while (i < g_aitems)
	{
		if (l_a[i] > big)
			big = l_a[i];
		i++;
	}
	if (l_a[0] == big)
		return (1);
	return (0);
}

int		ft_count_unsorted(int *l_a)
{
	int i;
	int ok;
	int *sorted;

	i = 0;
	ok = 0;
	sorted = ft_bubble_sort(l_a);
	while (i < g_aitems)
	{
		if (l_a[i] == sorted[i])
			ok++;
		else
			break;
		i++;
	}
	free(sorted);
	return (g_aitems - ok);
}

int		ft_other_than_first_two_list_is_sorted(int *l_a)
{
	int i;

	i = 2;
	while (i < g_aitems - 1)
	{
		if (l_a[i] > l_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_execute_operations_case_x(int *l_a, t_pslist **ops)
{
	ft_swap(l_a);
	ft_add_to_list(ops, 1);
	ft_rotate_first_to_end(l_a);
	ft_add_to_list(ops, 6);
	ft_rotate_first_to_end(l_a);
	ft_add_to_list(ops, 6);
}

void	ft_execute_operations_case_y(int *l_a, t_pslist **ops, int *l_b)
{
	ft_push(l_a, l_b);
	ft_add_to_list(ops, 4);
	ft_rotate_first_to_end(l_a);
	ft_add_to_list(ops, 6);
}

void	ft_solve_case_special(int *l_a, t_pslist **ops, int *l_b)
{
	int items;
	int unsorted;
	int count;

	items = g_aitems;
	unsorted = ft_count_unsorted(l_a);
	count = 0;
	while (!ft_l_a_is_complete_and_sorted(l_a, items))
	{
		while (!ft_l_a_is_sorted(l_a))
		{
			while (!ft_biggest_is_first(l_a))
			{
				ft_rotate_last_to_start(l_a);
				ft_add_to_list(ops, 9);
				count++;
			}
			if (unsorted == count && l_a[0] > l_a[1] && ft_other_than_first_two_list_is_sorted(l_a))
				ft_execute_operations_case_x(l_a, ops);
			else
			{
				ft_pushb(l_b, l_a);
				ft_add_to_list(ops, 5);
				count--;
				unsorted--;
			}
		}
		if (!ft_l_a_is_complete_and_sorted(l_a, items))
			ft_execute_operations_case_y(l_a, ops, l_b);
	}
}
