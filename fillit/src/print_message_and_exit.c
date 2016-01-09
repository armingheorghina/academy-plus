/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message_and_exit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:00:46 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/09 16:00:53 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_message_and_exit(char *message, int output)
{
	ft_putendl_fd(message, output);
	exit(0);
}

void	print_map_and_exit(char *str, int output)
{
	ft_putstr_fd(str, output);
	exit(0);
}
