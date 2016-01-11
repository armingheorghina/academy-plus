/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:02:53 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/11 17:06:30 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_result(int *l_a, int items)
{
	int i;

	i = 0;
	while (i < items)
	{
		ft_putnbr(l_a[i]);
		if (i < items - 1)
			ft_putchar(' ');
		i++;
	}
}
