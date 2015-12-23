/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alcu.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anflorea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 13:10:30 by anflorea          #+#    #+#             */
/*   Updated: 2015/12/21 17:20:27 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALCU_H
# define FT_ALCU_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_alcu
{
	struct s_alcu	*next;
	int				value;
	int				first;
}					t_alcu;

void				ft_print_map(t_alcu *lst);
void				ft_go_to_menu(t_alcu **lst);
int					get_user_input(int this_line);
void				ft_clear_screen(void);
void				ft_print_file(int fd);
void				ft_print_welcome_msg(void);
void				ft_print_winner(int winner);
int					ft_print_error(void);
t_alcu				*ft_create_node(int nbr);
void				ft_push_back(t_alcu **begin_list, int nbr);

#endif
