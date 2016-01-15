/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 17:09:59 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/14 16:06:04 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_to_list(t_pslist **begin, int o)
{
	t_pslist	*new;
	t_pslist	*list;

	new = (t_pslist*)malloc(sizeof(*new));
	new->operation = o;
	new->next = NULL;
	list = *begin;
	if (list == NULL)
		*begin = new;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
}
