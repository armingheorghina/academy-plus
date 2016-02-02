/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:05:05 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/02 16:05:14 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_env *m, int keycode)
{
	if (keycode == 115)
		m->spacing *= 1.2;
	if (keycode == 119)
		m->spacing /= 1.2;
}

void	ft_change_color(t_env *m, int keycode)
{
	if (keycode == 15)
		m->color = 'r';
	if (keycode == 5)
		m->color = 'g';
	if (keycode == 11)
		m->color = 'b';
}
