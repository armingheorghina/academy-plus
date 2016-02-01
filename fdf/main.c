/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:53:02 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/01 15:03:15 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_control_height(t_env *m, int control)
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			if (m->map2[i][j].z != 0 && control == 1)
				m->map2[i][j].z *= 2;
			if (m->map2[i][j].z != 0 && control == -1)
				m->map2[i][j].z /= 2;
			j++;
		}
		i++;
	}
}

void	ft_move(t_env *m, int keycode)
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			if (keycode == 126)
			{
				m->map2[i][j].x -= 1;
				m->map2[i][j].y -= 1;
			}
			if (keycode == 125)
			{
				m->map2[i][j].x += 1;
				m->map2[i][j].y += 1;
			}
			if (keycode == 123)
			{
				m->map2[i][j].x -= 1;
				m->map2[i][j].y += 1;
			}
			if (keycode == 124)
			{
				m->map2[i][j].x += 1;
				m->map2[i][j].y -= 1;
			}
			j++;
		}
		i++;
	}
}

int		key_hook(int keycode, t_env *m)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 116)
	{
		ft_control_height(m, 1);
		expose_hook(m);
	}
	if (keycode == 121)
	{
		ft_control_height(m, -1);
		expose_hook(m);
	}
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
	{
		ft_move(m, keycode);
		expose_hook(m);
	}
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

float	ft_fabs(float a)
{
	if ( a < 0)
		return (-a);
	return (a);
}

float 	ft_fmax(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	draw_line(t_point v1, t_point v2, t_env *m)
{
	float step;
	float t;
	t_point sum;

	t = 0;
	step = (float)(1 / (ft_fmax(ft_fabs(v1.x - v2.x), ft_fabs(v1.y - v2.y)) * 2));
	while (t <=1)
	{
		sum.x = v1.x + t * (v2.x - v1.x);
		sum.y = v1.y + t * (v2.y - v1.y);
		mlx_pixel_put(m->mlx, m->win, sum.x, sum.y, 0xFFFFFF);
		t = t + step;
	}
}

void	ft_draw_lines_between_points(t_point **matrix, t_env *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			if (j < m->columns - 1)
				draw_line(matrix[i][j], matrix[i][j + 1], m);
			if (i < m->rows - 1)
				draw_line(matrix[i][j], matrix[i + 1][j], m);
			j++;
		}
		i++;
	}
}

t_point	**ft_project_isometric_matrix(t_env *m)
{
	t_point	**matrix;
	int 	i;
	int		j;

	matrix = (t_point**)malloc(sizeof(*matrix) * m->rows);
	i = 0;
	while (i < m->rows)
	{
		matrix[i] = (t_point*)malloc(sizeof(t_point) * m->columns);
		j = 0;
		while (j < m->columns)
		{
			matrix[i][j].x = WIDTH / 2 + m->map2[i][j].x * SPACING * cos(DEG30) - m->map2[i][j].y * SPACING * cos(DEG30);
			matrix[i][j].y = HEIGHT / 2 + m->map2[i][j].x * SPACING * sin(DEG30) + m->map2[i][j].y * SPACING * sin(DEG30) - m->map2[i][j].z * SPACING;

			j++;
		}
		i++;
	}
	return (matrix);
}

int		expose_hook(t_env *m)
{
	int i;
	int j;
	t_point **matrix;

	matrix = ft_project_isometric_matrix(m);
	mlx_clear_window(m->mlx, m->win);
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			mlx_pixel_put(m->mlx, m->win, matrix[i][j].x, matrix[i][j].y, 0xFFFFFF);
			j++;
		}
		i++;
	}
	ft_draw_lines_between_points(matrix, m);
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
		if (str[i] == ' ')
			ok--;
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
			(m->map2)[i][j].x -= (m->columns / 2);
			(m->map2)[i][j].y -= (m->rows / 2);
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
	ft_transform_all_points_relative_to_map_center(m);
	mlx_expose_hook(m->win, expose_hook, m);
	mlx_key_hook(m->win, key_hook, m);
	mlx_loop(m->mlx);
	return (0);
}
