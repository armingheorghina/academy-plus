/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:06:41 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/20 23:52:28 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_recreate_origin(int *l_b)
{
	int i;

	i = 0;
	while (i < g_bitems - 1)
	{
		l_b[i] = l_b[i + 1];
		i++;
	}
	(g_bitems)--;
}

void	ft_recreate_borigin(int *l_b)
{
	int i;

	i = 0;
	while (i < g_aitems - 1)
	{
		l_b[i] = l_b[i + 1];
		i++;
	}
	(g_aitems)--;
}

void	ft_pushb(int *l_a, int *l_b)
{
	int	temp;
	int	temp2;
	int	i;

	if (!g_aitems)
		return ;
	if (g_bitems)
	{
		i = 1;
		temp = l_a[0];
		l_a[0] = l_b[0];
		while (i < g_bitems + 1)
		{
			if (i < g_bitems)
				temp2 = l_a[i];
			l_a[i] = temp;
			temp = temp2;
			i++;
		}
	}
	else
		l_a[0] = l_b[0];
	ft_recreate_borigin(l_b);
	(g_bitems)++;
}

void	ft_push(int *l_a, int *l_b)
{
	int	temp;
	int	temp2;
	int	i;

	if (!g_bitems)
		return ;
	if (g_aitems)
	{
		i = 1;
		temp = l_a[0];
		l_a[0] = l_b[0];
		while (i < g_aitems + 1)
		{
			if (i < g_aitems)
				temp2 = l_a[i];
			l_a[i] = temp;
			temp = temp2;
			i++;
		}
	}
	else
		l_a[0] = l_b[0];
	ft_recreate_origin(l_b);
	(g_aitems)++;
}

void	ft_rotate_first_to_endb(int *l_a)
{
	int temp;
	int i;

	if (g_bitems < 2)
		return ;
	i = 0;
	temp = l_a[0];
	while (i < g_bitems - 1)
	{
		l_a[i] = l_a[i + 1];
		i++;
	}
	l_a[g_bitems - 1] = temp;
}

void	ft_rotate_first_to_end(int *l_a)
{
	int temp;
	int i;

	if (g_aitems < 2)
		return ;
	i = 0;
	temp = l_a[0];
	while (i < g_aitems - 1)
	{
		l_a[i] = l_a[i + 1];
		i++;
	}
	l_a[g_aitems - 1] = temp;
}

void	ft_rotate_last_to_startb(int *l_a)
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
}

void	ft_rotate_last_to_start(int *l_a)
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
}

void	ft_push_swap(int *l_a, int items, int *l_b)
{
	int		route;
	t_pslist	*ops;

	ops = NULL;
	g_aitems = items;
	g_bitems = 0;
	if (ft_nbr_of_sorted_is_bigger_than_unsorted(l_a))
		ft_solve_case_special(l_a, &ops, l_b);
	else if (ft_l_a_is_sorted_decreasing(l_a) && items > 2)
		ft_solve_decreasing_list(l_a, &ops, l_b);
	else
	{
		while (!ft_l_a_is_complete_and_sorted(l_a, items))
		{
			while (!ft_l_a_is_sorted(l_a))
			{
				if (g_aitems == 3 && l_a[0] < l_a[1] && l_a[1] > l_a[2] && l_a[0] < l_a[2])
				{
					ft_swap(l_a);
					ft_add_to_list(&ops, 1);
					ft_rotate_first_to_end(l_a);
					ft_add_to_list(&ops, 6);
				}
				else
				{
					route = ft_find_shortest_route_of_smallest_number(l_a);
					if (route == 1)
						ft_execute_route_1(l_a, &ops, l_b);
					else
						ft_execute_route_2(l_a, &ops, l_b);
				}
			}
			if (!ft_l_a_is_complete_and_sorted(l_a, items))
			{
				ft_push(l_a, l_b);
				ft_add_to_list(&ops, 4);
			}
		}
	}
	ft_print_list(ops);
}
