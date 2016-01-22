/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:38:16 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/22 14:38:33 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_first_to_end(int *l_a, t_pslist **ops)
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
	ft_add_to_list(ops, 6);
}
