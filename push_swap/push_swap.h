/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:34:27 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/20 23:34:23 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

int g_aitems;
int g_bitems;
typedef	struct		s_pslist
{
	int				operation;
	struct s_pslist	*next;
}					t_pslist;

void	ft_error_and_exit(void);
void	ft_validate_input(int argc, char **argv);
void	ft_print_result(int *l_a, int items);
void	ft_print_list(t_pslist *list);
void	ft_add_parameters_to_l_a(int *l_a, int items, char **argv);
void	ft_push_swap(int *l_a, int items, int *l_b);
void	ft_swap(int *l_a);
void	ft_swapb(int *l_a);
void	ft_push(int *l_a, int *l_b);
void	ft_pushb(int *l_a, int *l_b);
void	ft_rotate_first_to_end(int *l_a);
void	ft_rotate_first_to_endb(int *l_a);
void	ft_rotate_last_to_start(int *l_a);
void	ft_rotate_last_to_startb(int *l_a);
int	*ft_bubble_sort(int *l_a);

int	ft_l_a_is_complete_and_sorted(int *l_a, int items);
int	ft_l_a_is_sorted(int *l_a);
int	ft_find_shortest_route_of_smallest_number(int *l_a);
int	ft_find_smallest_number(int *l_a);
int	ft_find_its_position(int *l_a, int small);
void	ft_execute_route_1(int *l_a, t_pslist **ops, int *l_b);
void	ft_execute_route_2(int *l_a, t_pslist **ops, int *l_b);
int		ft_smallest_is_first(int *tab);
void	ft_add_to_list(t_pslist **ops, int o);
int		ft_nbr_of_sorted_is_bigger_than_unsorted(int *l_a);
void	ft_solve_case_special(int *l_a, t_pslist **ops, int *l_b);
void	ft_solve_decreasing_list(int *l_a, t_pslist **ops, int *l_b);
int	ft_l_a_is_sorted_decreasing(int *l_a);
#endif
