/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:57:39 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/01 18:03:34 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# define WIDTH 800
# define HEIGHT 800
# define DEG30 0.52398776

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
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
	float			spacing;
	float			zmin;
	float			zmax;
	int				color;
}					t_env;
int		expose_hook(t_env *m);
void	ft_error_and_exit(void);
void	ft_print_int_map(t_env *m);
void	ft_print_cmap(char **cmap);
void	ft_print_struct_matrix(t_env *m);
#endif
