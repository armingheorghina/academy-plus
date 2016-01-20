/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:23:47 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/20 22:13:02 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*ft_tab_copy(int *copy, int *l_a)
{
	int i;

	i = 0;
	while (i < g_aitems)
	{
		copy[i] = l_a[i];
		i++;
	}
	return (copy);
}

void	ft_swap_2(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		*ft_bubble_sort(int *l_a)
{
	int	*copy;
	int i;
	int j;

	i = 0;
	copy = (int*)malloc(sizeof(*copy) * g_aitems);
	copy = ft_tab_copy(copy, l_a);
	while (i < g_aitems)
	{
		j = i + 1;
		while (j < g_aitems)
		{
			if (copy[j] < copy[i])
				ft_swap_2(&copy[i], &copy[j]);
			j++;
		}
		i++;
	}
	return (copy);
}
