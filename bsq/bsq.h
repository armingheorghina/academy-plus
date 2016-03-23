/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 19:34:13 by vdruta            #+#    #+#             */
/*   Updated: 2016/03/22 16:33:00 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define BUF_SIZE 1
# include "libft/libft.h"
# include <stdio.h>

typedef	struct	s_param
{
	int		lin;
	int 	col;
	int 	max;
	int 	pos[2];
	char 	vid;
	char 	obst;
	char 	plin;
}				t_param;

void	ft_putchar(char c);
void	ft_print_map(char **map);
char	*ft_open_read_stock(char *filename);
char	*ft_find_str_number(char *str);
int	ft_find_number(char *str);
char	ft_find_vid(char *str);
char	ft_find_obstacol(char *str);
char	ft_find_plin(char *str);
int	ft_line_lenght(char *str);
char	**ft_map(char *str, int i);
int	ft_find_map_lines(char **str);
int	ft_val_nr_linii(char *str, char **map);
int	ft_find_1st_line_lenght(char **str);
int	ft_val_lung_linii(char *str, char **map);
void	ft_argc_bigger_than_1(int argc, char **argv);
int	ft_val_fisier_gol(char *str);
void	ft_argc_is_one(int argc);
void	ft_first_col_one(char **map, int **m, t_param *param);
void	ft_first_line_one(char **map, int **m, t_param *param);
int	minim(int a, int b, int c);
void	ft_find_max_number(char **map, int **m, t_param *param);
void	generare_matrice(char **map, t_param *param);

#endif
