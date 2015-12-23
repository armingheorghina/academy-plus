/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:28:08 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/21 16:40:19 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alcu.h"

t_alcu	*ft_create_node(int nbr)
{
	t_alcu	*new;

	new = (t_alcu*)malloc(sizeof(t_alcu));
	new->next = NULL;
	new->value = nbr;
	new->first = 0;
	return (new);
}

void	ft_push_back(t_alcu **begin_list, int nbr)
{
	t_alcu	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_node(nbr);
	}
	else
		*begin_list = ft_create_node(nbr);
}
