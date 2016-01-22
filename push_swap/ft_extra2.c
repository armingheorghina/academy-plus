/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:20:06 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/22 14:20:39 by vdruta           ###   ########.fr       */
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
			break ;
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
