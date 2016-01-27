/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:53:02 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/27 23:41:41 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env *m)
{
	if (keycode == 53)
		exit(0);
	ft_putnbr(keycode);
	ft_putchar('\n');
	(void)m;
	return (0);
}

int		expose_hook(t_env *m)
{
	int i;
	int j;
	float	x;
	float	y;

	mlx_clear_window(m->mlx, m->win);
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			x = (float)((m->map2)[i][j].x) / (m->map2)[i][j].z * -10 + WIDTH / 2;
			y = (float)((m->map2)[i][j].y) / (m->map2)[i][j].z * -10 + HEIGHT / 2;
			mlx_pixel_put(m->mlx, m->win, x, y, 0xFFFFFF);
			j++;
		}
		i++;
	}
	return (0);
}


char	**ft_get_cmap(char *filename, t_env *m)
{
	int		fd;
	char	*line;
	char	**map;
	int		ok;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(filename);
		exit(0);
	}
	ok = 0;
	while (ft_get_next_line(fd, &line))
		ok++;
	m->rows = ok;
	close(fd);
	map = (char**)malloc(sizeof(*map) * (ok + 1));
	fd = open(filename, O_RDONLY);
	i = 0;
	while (ft_get_next_line(fd, &line))
	{
		map[i] = line;
		i++;
	}
	map[i] = 0;
	return (map);
}

int		**ft_get_int_map(char **cmap, t_env *m)
{
	int i;
	int j;
	int **map;
	char **temp_map;

	map = (int**)malloc(sizeof(int*) * m->rows);
	temp_map = ft_strsplit(cmap[0], ' ');
	j = 0;
	while (temp_map[j])
		j++;
	m->columns = j;
	i = 0;
	while (cmap[i])
	{
		map[i] = (int*)malloc(sizeof(int) * m->columns);
		temp_map = ft_strsplit(cmap[i], ' ');
		j = 0;
		while (temp_map[j])
		{
			map[i][j] = ft_atoi(temp_map[j]);
			j++;
		}
		free(temp_map);
		if (j != m->columns)
			ft_error_and_exit();
		i++;
	}
	return (map);
}

t_point	**ft_generate_initial_coordinates(t_env *m)
{
	t_point **temp;
	int		i;
	int		j;

	temp = (t_point**)malloc(sizeof(*temp) * (m->rows));
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		temp[i] = (t_point*)malloc(sizeof(t_point) * m->columns);
		while (j < m->columns)
		{
			temp[i][j].x = j;
			temp[i][j].y = i;
			temp[i][j].z = m->map[i][j];
			j++;
		}
		i++;
	}
	return (temp);
}

void	ft_validate_cmap_line(char *str)
{
	int i;
	int ok;

	i = 0;
	ok = 0;
	while (str[i])
	{
		if (str[i] == '-')
			ok++;
		i++;
	}
	if (ok > 1)
		ft_error_and_exit();
}

void	ft_validate_char_map(char **cmap)
{
	int i;
	int j;
	int k;
	char **tmp;

	i = 0;
	while (cmap[i])
	{
		ft_validate_cmap_line(cmap[i]);
		j = 0;
		tmp = ft_strsplit(cmap[i], ' ');
		while (tmp[j])
		{
			k = 0;
			while (tmp[j][k])
			{
				if (ft_isdigit(tmp[j][k]) || tmp[j][k] == '-')
					k++;
				else
					ft_error_and_exit();
			}
			j++;
		}
		free(tmp);
		i++;
	}

}

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
		m->file = argv[1];
		m->mlx = mlx_init();
		m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, m->file);
		cmap = ft_get_cmap(m->file, m);
		ft_validate_char_map(cmap);
		ft_print_cmap(cmap); // delete this
		m->map = ft_get_int_map(cmap, m);
		ft_print_int_map(m); // delete this
		m->map2 = ft_generate_initial_coordinates(m);
		ft_print_struct_matrix(m); //delete this
	}
}

void	ft_distantiate_points(t_env *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			(m->map2)[i][j].x *= SPACING;
			(m->map2)[i][j].y *= SPACING;
			j++;
		}
		i++;
	}
}

void	ft_transform_all_points_relative_to_map_center(t_env *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			(m->map2)[i][j].x -= (m->columns / 2) * SPACING;
			(m->map2)[i][j].y -= (m->rows / 2) * SPACING;
			j++;
		}
		i++;
	}
}

void	ft_rotate_45(t_env *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			(m->map2)[i][j].z = m->map2[i][j].z - (m->rows / 2) + i;
			(m->map2)[i][j].y += (m->map2)[i][j].z / 4;
			(m->map2)[i][j].z = m->map2[i][j].z - 20;
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_env *m;

	m = (t_env*)malloc(sizeof(*m));
	ft_init_env(m, argc, argv);
	ft_distantiate_points(m);
	ft_transform_all_points_relative_to_map_center(m);
		ft_print_struct_matrix(m);
	ft_rotate_45(m);
		ft_print_struct_matrix(m);
	//ft_push_all_in_depth(m);
	mlx_expose_hook(m->win, expose_hook, m);
	mlx_key_hook(m->win, key_hook, m);
	mlx_loop(m->mlx);
	return (0);
}
