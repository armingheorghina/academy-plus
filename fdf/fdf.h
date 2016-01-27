/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:57:39 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/27 23:41:47 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# define WIDTH 800
# define HEIGHT 800
# define SPACING 30

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
}				t_point;

typedef struct	s_env
{
	void			*win;
	void			*mlx;
	char			*file;
	int				**map;
	t_point			**map2;
	int				columns;
	int				rows;
}					t_env;

void	ft_error_and_exit(void);
void	ft_print_int_map(t_env *m);
void	ft_print_cmap(char **cmap);
void	ft_print_struct_matrix(t_env *m);
#endif
