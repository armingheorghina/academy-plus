/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 17:09:59 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/12 17:47:10 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_expected(int i, int *l_a, int items, int *l_sorted)
{
	int	j;

	j = 0;
	while (j < items)
	{
		if (l_a[i] == l_sorted[j])
			return (j);
		j++;
	}
	return (j);
}

void	ft_add_to_list(t_pslist **list, int *l_sorted, int *l_a, int items)
{
	int			i;
	t_pslist	*start;

	*list = (t_pslist*)malloc(sizeof(t_pslist));
	i = 0;
	start = *list;
	start->initial_position = i;
	start->expected_position = ft_find_expected(i, l_a, items, l_sorted);
	i++;
	while (i < items)
	{
		start->next = (t_pslist*)malloc(sizeof(t_pslist));
		start = start->next;
		start->initial_position = i;
		start->expected_position =  ft_find_expected(i, l_a, items, l_sorted);
		i++;
	}
	start->next = NULL;
}
