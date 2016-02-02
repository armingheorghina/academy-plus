/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:56:18 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/02 17:32:27 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(t_env *m, t_point v)
{
	int red;
	int green;
	int blue;

	if (v.z == m->zmin || v.z < 0.00001)
		return (0xFFFFFF);
	red = v.z / (m->zmax) * 255;
	blue = (red << 16) + (red << 8);
	green = (red << 16) + red;
	red = (red << 8) + red;
	if (m->color == 'r')
		return (0xFFFFFF - red);
	if (m->color == 'b')
		return (0xFFFFFF - blue);
	return (0xFFFFFF - green);
}
