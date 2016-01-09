/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:45:51 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/09 15:53:15 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

typedef struct		s_tetris
{
	unsigned char	*coordinates;
	char			letter;
	char			clone;
	struct s_tetris	*next;
}					t_tetris;

void				print_message_and_exit(char *message, int output);
void				print_map_and_exit(char *str, int output);
t_tetris			*get_tetris_pieces(char *filename);
void				get_tetriminos(t_tetris **tetriminos, int fd);
char				**get_piece(int fd);
unsigned char		*get_coordinates(char **piece);
void				adjust_coordinates(unsigned char *coordinates);
void				add_piece_to_list(t_tetris **tetriminos,
							unsigned char *coordinates,	char letter);
void				fillit(t_tetris *list);
void				change_coordinates(t_tetris *list, unsigned char size);
void				increment_coordinates(t_tetris *list, unsigned char size);
void				backtrack(t_tetris *tetriminos, char *map);
/*
void				print_map(char **map);
void				print_map_temp(char **map);
char				**save_valid_map(char **map);
void				back(t_tetris *list, char **map);
*/
#endif
