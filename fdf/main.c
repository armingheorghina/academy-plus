/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:53:02 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/27 13:24:12 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int		main()
{
	void *mlx;
	void *win;
	int x;
	int y;


	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "fdf");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
	return (0);
}
