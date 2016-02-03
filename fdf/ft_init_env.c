/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:02:00 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/03 17:01:49 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_env(t_env *m, int argc, char **argv)
{
	char **cmap;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf filename\n");
		exit(0);
	}
	else
	{
		m->color = 'r';
		m->file = argv[1];
		m->mlx = mlx_init();
		m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, m->file);
		cmap = ft_get_cmap(m->file, m);
		ft_validate_char_map(cmap);
		m->map = ft_get_int_map(cmap, m);
		m->map2 = ft_generate_initial_coordinates(m);
		m->map3 = ft_generate_initial_coordinates(m);
		m->spacing = (WIDTH) / (m->columns + 70);
		m->eye.x = 0;
		m->eye.y = 0;
		m->eye.z = (WIDTH / 2) * tan(DEG15);
		m->projection_type = 'i';
	}
}
