/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:27:59 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/08 14:34:29 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_add_to_list(t_lemin **list, char *line)
{
	t_lemin	*new;
	t_lemin	*start;

	new = (t_lemin*)malloc(sizeof(*new));
	new->input_line = line;
	new->next = NULL;
	start = *list;
	if (start == NULL)
		*list = new;
	else
	{
		while (start->next)
			start = start->next;
		start->next = new;
	}
}
