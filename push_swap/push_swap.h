/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:34:27 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/14 16:10:57 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef	struct		s_pslist
{
	int				operation;
	struct s_pslist	*next;
}					t_pslist;

void	ft_error_and_exit(void);
void	ft_print_result(int *l_a, int items);
void	ft_print_list(t_pslist *list);
void	ft_add_parameters_to_l_a(int *l_a, int items, char **argvi);
void	ft_push_swap(int *l_a, int items, int *l_b);
void	ft_swap(int *l_a, int aitems);
void	ft_push(int *l_a, int *aitems, int *l_b, int *bitems);
void	ft_rotate_first_to_end(int *l_a, int aitems);
void	ft_rotate_last_to_start(int *l_a, int aitems);
int	*ft_bubble_sort(int *l_a, int aitems);

int	ft_l_a_is_complete_and_sorted(int *l_a, int aitems, int items);
int	ft_find_shortest_route_of_smallest_number(int *l_a, int aitems);
int	ft_find_smallest_number(int *l_a, int aitems);
int	ft_find_its_position(int *l_a, int aitems, int small);
void	ft_execute_route_1(int *l_a, int aitems, t_pslist **ops);
void	ft_add_to_list(t_pslist **ops, int o);
#endif
