/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:42:37 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/20 22:26:06 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapb(int *l_a)
{
	int	temp;

	if (g_bitems < 2)
		return ;
	temp = l_a[0];
	l_a[0] = l_a[1];
	l_a[1] = temp;
}

void	ft_swap(int *l_a)
{
	int	temp;

	if (g_aitems < 2)
		return ;
	temp = l_a[0];
	l_a[0] = l_a[1];
	l_a[1] = temp;
}
