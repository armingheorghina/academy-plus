/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:06:41 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/11 18:09:54 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_or_sb(int *l_a)
{
	int	temp;

	if (!l_a[0] || !l_a[1])
		return ;
	temp = l_a[0];
	l_a[0] = l_a[1];
	l_a[1] = temp;
}

void	ft_pa(int *l_a, int *l_b, int items)
{
	int	temp;
	int	i;

	if (!l_b[0])
		return ;
	i = 1;
	temp = l_a[0];
	l_a[0] = l_b[0];
	while (i < items + 1)
	{
		temp = l_a[i];
		l_a[i] = l_a[i - 1];
		
		i++;
	}
	items++;
}

void	ft_pb(int *l_a, int *l_b)
{
	int temp;

	temp = l_b[0];
	l_b[0] = l_a[0];
	l_a[0] = temp;
}

void	ft_push_swap(int *l_a, int items, int *l_b)
{
	ft_sa_or_sb(l_a);
	ft_pa(l_a, l_b, items);
	ft_pb(l_a, l_b);
}
