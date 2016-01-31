/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlucaci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:59:04 by nlucaci           #+#    #+#             */
/*   Updated: 2016/01/31 22:49:59 by nlucaci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_H
# define WONG_H
#include "libft/libft.h"
#define	WIN_NUMBER 2048
#define size 0
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int s[6][6];
int mov;
int g_score;

void ft_put_nbr_in_table();
int	ft_is_pow_of_two();
void ft_print();
void scrie();
int	ft_verify_map();
void varianta_B(int i, int direction);
void varianta_A(int j, int direction);
#endif
