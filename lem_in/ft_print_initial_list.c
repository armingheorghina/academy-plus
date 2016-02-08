/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_initial_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:19:59 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/08 14:35:36 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_initial_list(t_lemin *list)
{
	while (list)
	{
		ft_putstr(list->input_line);
		ft_putchar('\n');
		list = list->next;
	}
}
