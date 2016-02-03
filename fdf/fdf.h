/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:57:39 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/03 17:13:37 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# define WIDTH 1000
# define HEIGHT 1000
# define DEG30 0.52398776
# define DEG15 0.261799388

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef struct	s_env
{
	void		*win;
	void		*mlx;
	char		*file;
	int			**map;
	t_point		**map2;
	t_point		**map3;
	int			columns;
	int			rows;
	float		spacing;
	float		zmin;
	float		zmax;
	int			color;
	t_point		eye;
	int			projection_type;
}				t_env;

void			ft_rotate(t_env *m, int keycode);
int				expose_hook(t_env *m);
void			ft_error_and_exit(void);
void			ft_print_int_map(t_env *m);
void			ft_print_cmap(char **cmap);
void			ft_print_struct_matrix(t_env *m);
int				ft_color(t_env *m, t_point v);
void			ft_control_height(t_env *m, int control);
void			ft_move(t_env *m, int keycode);
void			ft_zoom(t_env *m, int keycode);
void			ft_change_color(t_env *m, int keycode);
int				key_hook(int keycode, t_env *m);
void			draw_line(t_point v1, t_point v2, t_env *m);
float			ft_fmin(float a, float b);
float			ft_fmax(float a, float b);
float			ft_fabs(float a);
void			ft_draw_lines_between_points(t_point **matrix, t_env *m);
t_point			**ft_project_isometric_matrix(t_env *m);
t_point			**ft_project_perspective_matrix(t_env *m);
float			ft_get_zmin(t_point **matrix, t_env *m);
float			ft_get_zmax(t_point **matrix, t_env *m);
void			ft_show_usage(t_env *m);
int				expose_hook(t_env *m);
char			**ft_get_cmap(char *filename, t_env *m);
int				**ft_get_int_map(char **cmap, t_env *m);
t_point			**ft_generate_initial_coordinates(t_env *m);
void			ft_validate_char_map(char **cmap);
void			ft_init_env(t_env *m, int argc, char **argv);
void			ft_transform_all_points_relative_to_map_center(t_env *m);
#endif
