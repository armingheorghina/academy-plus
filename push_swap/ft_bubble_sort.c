/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:23:47 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/12 17:07:04 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*ft_tab_copy(int *copy, int *l_a, int aitems)
{
	int i;

	i = 0;
	while (i < aitems)
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

int		*ft_bubble_sort(int *l_a, int aitems)
{
	int	*copy;
	int i;
	int j;

	i = 0;
	copy = (int*)malloc(sizeof(*copy) * aitems);
	copy = ft_tab_copy(copy, l_a, aitems);
	while (i < aitems)
	{
		j = i + 1;
		while (j < aitems)
		{
			if (copy[j] < copy[i])
				ft_swap_2(&copy[i], &copy[j]);
			j++;
		}
		i++;
	}
	return (copy);
}
