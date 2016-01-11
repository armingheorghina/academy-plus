/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:34:27 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/11 18:09:58 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
typedef	struct		s_pslist
{
	int				*l_a;
	int				a_items;
	int				*l_b;
	struct s_pslist	*next;
}					t_pslist;
void	ft_error_and_exit(void);
void	ft_print_result(int *l_a, int items);
void	ft_add_parameters_to_l_a(int *l_a, int items, char **argvi);
void	ft_push_swap(int *l_a, int items, int *l_b);
void	ft_sa_or_sb(int *l_a);
void	ft_pa(int *l_a, int *l_b);
void	ft_pb(int *l_a, int *l_b);
#endif
