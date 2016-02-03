/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:42:48 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/03 16:47:01 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_show_usage(t_env *m)
{
	mlx_string_put(m->mlx, m->win, 10, 10, 0xFFFFFF, "Usage:");
	mlx_string_put(m->mlx, m->win, 10, 30, 0xFFFFFF,
			"Directional keys to move");
	mlx_string_put(m->mlx, m->win, 10, 50, 0xFFFFFF, "Zoom: Home/End");
	mlx_string_put(m->mlx, m->win, 10, 70, 0xFFFFFF, "Height: PageUp/PageDown");
	mlx_string_put(m->mlx, m->win, 10, 90, 0xFFFFFF,
			"Color: (r)ed, (g)reen, (b)lue");
	mlx_string_put(m->mlx, m->win, 10, 110, 0xFFFFFF, "Change projection type : p");
	mlx_string_put(m->mlx, m->win, 10, 130, 0xFFFFFF, "Exit: Esc");
}
