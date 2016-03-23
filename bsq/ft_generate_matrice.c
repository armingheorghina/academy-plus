/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_matrice.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 22:18:32 by azaha             #+#    #+#             */
/*   Updated: 2015/09/24 22:19:23 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

int		minim(int a, int b, int c);
void	ft_first_line_one(char **map, int **m, t_param *param);
void	ft_first_col_one(char **map, int **m, t_param *param);
void	ft_print_solution(int **matr, t_param *param);
void	ft_gen_matrice(char **map, int **m, t_param *param);

void	generare_matrice(char **map, t_param *param)
{
	int k;
	int **m;

	k = 0;
	m = (int**)malloc(sizeof(int*) * (param->lin + 1));
	while (k < param->lin)
	{
		m[k] = (int*)malloc(sizeof(int) * (param->col + 1));
		k++;
	}
	ft_first_line_one(map, m, param);
	ft_first_col_one(map, m, param);
	ft_gen_matrice(map, m, param);
	ft_print_solution(m, param);
}
