/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:36:34 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/14 15:18:52 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_l_a_is_complete_and_sorted(int *l_a, int aitems, int items)
{
	int i;

	i = 0;
	if (aitems != items)
		return (0);
	while (i < aitems - 1)
	{
		if (l_a[i] > l_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_smallest_number(int *l_a, int aitems)
{
	int i;
	int small;
	
	small = l_a[0];
	i = 1;
	while (i < aitems)
	{
		if (l_a[i] < small)
			small = l_a[i];
		i++;
	}
	return (small);
}

int		ft_find_its_position(int *l_a, int aitems, int small)
{
	int i;

	i = 0;
	while (i < aitems)
	{
		if (l_a[i] == small)
			return (i);
		i++;
	}
	return (-1); //in case of error
}

int		ft_find_shortest_route_of_smallest_number(int *l_a, int aitems)
{
	int small;
	int position;
	int route; // 2 to left, 1 to right

	small = ft_find_smallest_number(l_a, aitems);
	position = ft_find_its_position(l_a, aitems, small);
	if ((aitems % 2) == 0) //lista para de numere
	{
		if (((aitems / 2) - 1) < position)
			route = 1;
		else
			route = 2;
	}
	else //lista impara
	{
		if ((aitems / 2) == position)
			route = 0;
		else if ((aitems / 2) < position)
			route = 1;
		else
			route = 2;
	}
	return (route);
}
