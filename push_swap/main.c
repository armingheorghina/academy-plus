/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:35:47 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/20 22:11:58 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	int		*l_a;
	int		*l_b;

	l_a = (int*)malloc(sizeof(*l_a) * (argc - 1));
	l_b = (int*)malloc(sizeof(*l_b) * (argc - 1));
	if (argc < 2)
		ft_error_and_exit();
	else
	{
		ft_validate_input(argc, argv);
		ft_add_parameters_to_l_a(l_a, (argc - 1), argv);
		ft_push_swap(l_a, argc - 1, l_b);
	}
	return (0);
}
