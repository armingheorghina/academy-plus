/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anflorea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 13:10:53 by anflorea          #+#    #+#             */
/*   Updated: 2015/12/21 16:40:46 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alcu.h"

t_alcu	*ft_get_this_line(t_alcu *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_alcu	*ft_remove_last(t_alcu **lst)
{
	t_alcu	*new;

	new = *lst;
	if ((*lst)->next)
	{
		while (((*lst)->next)->value)
			*lst = (*lst)->next;
		free((*lst)->next);
		(*lst)->next = NULL;
	}
	*lst = new;
	return (ft_get_this_line(*lst));
}

int		ft_think_it(t_alcu *lst, t_alcu *this_line)
{
	int		choice;

	(void)lst;
	if (this_line->first == 1)
	{
		choice = this_line->value % 4 - 1;
		if (choice == -1)
			return (3);
		if (choice == 0)
			return (1);
	}
	else
	{
		choice = this_line->value % 4;
		if (choice == 0)
			return (1);
	}
	return (choice);
}

int		ft_computer_choice(t_alcu *lst, t_alcu *this_line)
{
	int		computer_input;

	computer_input = ft_think_it(lst, this_line);
	ft_putstr("I chose: ");
	ft_putnbr(computer_input);
	ft_putchar('\n');
	return (computer_input);
}

void	ft_go_to_menu(t_alcu **lst)
{
	t_alcu	*this_line;
	int		user_input;
	int		turn;

	turn = 0;
	ft_clear_screen();
	ft_print_welcome_msg();
	this_line = ft_get_this_line(*lst);
	while (this_line->value)
	{
		ft_print_map(*lst);
		if (turn == 0)
			user_input = get_user_input(this_line->value);
		else
			user_input = ft_computer_choice(*lst, this_line);
		this_line->value -= user_input;
		if (this_line->value == 0)
			this_line = ft_remove_last(lst);
		turn = 1 - turn;
	}
	ft_print_winner(turn);
}
