/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:48:04 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/18 16:42:33 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int		ft_nbr_is_bigger_than_all_previous(int *l_a, int aitems, int nbr)
{
	int i;

	i = 0;
	while (i < aitems - 2)
	{
		if (l_a[i] > nbr)
			return (0);
		i++;
	}
	return (1);
}

int		ft_l_a_is_partialy_sorted(int *l_a, int aitems)
{
	int i;
	int *sorted;

	i = 0;
	if (aitems < 4)
		return (0);
	sorted = ft_bubble_sort(l_a, aitems);
	while (i < aitems - 2)
	{
		if (l_a[i] != sorted[i])
			return (0);
		i++;
	}
	if (!ft_nbr_is_bigger_than_all_previous(l_a, aitems, l_a[aitems - 2]))
		return (0);
	if (!ft_nbr_is_bigger_than_all_previous(l_a, aitems, l_a[aitems - 1]))
		return (0);
	return (1);
}

void	ft_execute_route_extra(int *l_a, int aitems, t_pslist **ops)
{
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
}
