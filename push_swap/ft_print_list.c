/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 14:47:43 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/22 14:26:53 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_space(char *str)
{
	ft_putstr(str);
	ft_putchar(' ');
}

void	ft_print_list_3(t_pslist *start)
{
	if (start->next && start->operation == 9 && (start->next)->operation == 10)
	{
		ft_putstr_space("rrr");
		start = start->next;
	}
	else if (start->operation == 9 && start->next)
		ft_putstr_space("rra");
	else if (start->operation == 9)
		ft_putstr("rra");
	else if (start->operation == 10 && start->next)
		ft_putstr_space("rrb");
	else if (start->operation == 10)
		ft_putstr("rrb");
}

void	ft_print_list_2(t_pslist *start)
{
	if (start->operation == 4 && start->next)
		ft_putstr_space("pa");
	else if (start->operation == 4)
		ft_putstr("pa");
	else if (start->operation == 5 && start->next)
		ft_putstr_space("pb");
	else if (start->operation == 5)
		ft_putstr("pb");
	else if (start->next && start->operation == 6 &&
			(start->next)->operation == 7)
	{
		ft_putstr_space("rr");
		start = start->next;
	}
	else if (start->operation == 6 && start->next)
		ft_putstr_space("ra");
	else if (start->operation == 6)
		ft_putstr("ra");
	else if (start->operation == 7 && start->next)
		ft_putstr_space("rb");
	else if (start->operation == 7)
		ft_putstr("rb");
	else
		ft_print_list_3(start);
}

void	ft_print_list(t_pslist *list)
{
	t_pslist *start;

	start = list;
	while (start)
	{
		if (start->next && start->operation == 1 &&
				(start->next)->operation == 2)
		{
			ft_putstr_space("ss");
			start = start->next;
		}
		else if (start->operation == 1 && start->next)
			ft_putstr_space("sa");
		else if (start->operation == 1)
			ft_putstr("sa");
		else if (start->operation == 2 && start->next)
			ft_putstr_space("sb");
		else if (start->operation == 2)
			ft_putstr("sb");
		else
			ft_print_list_2(start);
		start = start->next;
	}
	ft_putchar('\n');
}
