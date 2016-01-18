/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:06:41 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/18 17:48:45 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *l_a, int aitems)
{
	int	temp;

	if (aitems < 2)
		return ;
	temp = l_a[0];
	l_a[0] = l_a[1];
	l_a[1] = temp;
}

void	ft_recreate_origin(int *l_b, int *bitems)
{
	int i;

	i = 0;
	while (i < *bitems - 1)
	{
		l_b[i] = l_b[i + 1];
		i++;
	}
	(*bitems)--;
}

void	ft_push(int *l_a, int *aitems, int *l_b, int *bitems)
{
	int	temp;
	int	temp2;
	int	i;

	if (!*bitems)
		return ;
	if (*aitems)
	{
		i = 1;
		temp = l_a[0];
		l_a[0] = l_b[0];
		while (i < *aitems + 1)
		{
			if (i < *aitems)
				temp2 = l_a[i];
			l_a[i] = temp;
			temp = temp2;
			i++;
		}
	}
	else
		l_a[0] = l_b[0];
	ft_recreate_origin(l_b, bitems);
	(*aitems)++;
}

void	ft_rotate_first_to_end(int *l_a, int aitems)
{
	int temp;
	int i;

	if (aitems < 2)
		return ;
	i = 0;
	temp = l_a[0];
	while (i < aitems - 1)
	{
		l_a[i] = l_a[i + 1];
		i++;
	}
	l_a[aitems - 1] = temp;
}

void	ft_rotate_last_to_start(int *l_a, int aitems)
{
	int temp;
	int	i;

	if (aitems < 2)
		return ;
	temp = l_a[aitems - 1];
	i = aitems - 1;
	while (i > 0)
	{
		l_a[i] = l_a[i - 1];
		i--;
	}
	l_a[0] = temp;
}

void	ft_push_swap(int *l_a, int items, int *l_b)
{
	int		aitems;
	int		bitems;
	int		route;
	t_pslist	*ops;

	ops = NULL;
	aitems = items;
	bitems = 0;
	while (!ft_l_a_is_complete_and_sorted(l_a, aitems, items))
	{
	//	if (ft_l_a_is_partialy_sorted(l_a, aitems))
	//		ft_execute_route_extra(l_a, aitems, &ops);
	//	else //TODO list sorted but last 2 are not!!
	//	{
			while (!ft_l_a_is_sorted(l_a, aitems))
			{
				route = ft_find_shortest_route_of_smallest_number(l_a, aitems);
				if (route == 1)
					ft_execute_route_1(l_a, &aitems, &ops, l_b, &bitems);
				else
					ft_execute_route_2(l_a, &aitems, &ops, l_b, &bitems);
			}
			if (!ft_l_a_is_complete_and_sorted(l_a, aitems, items))
			{
				ft_push(l_a, &aitems, l_b, &bitems);
				ft_add_to_list(&ops, 4);
			}
	//	}
	}
	/*
	   ft_swap(l_a, aitems); //sa
	   ft_push(l_b, &bitems, l_a, &aitems); //pb
	   ft_rotate_first_to_end(l_a, aitems); //ra
	   ft_rotate_last_to_start(l_a, aitems); //rra
	   */
	//	ft_print_result(l_a, aitems);
	//	ft_putchar('\n');
	ft_print_list(ops);
	//	ft_print_result(l_b, bitems);
}
