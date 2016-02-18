/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:12:09 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/17 19:31:16 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

int				g_start;
int 				g_end;
int				g_ants;

typedef struct			s_lemin
{
	char			*input_line;
	struct s_lemin		*next;
}				t_lemin;

typedef struct			s_vertices
{
	int			id;
	char			*name;
	int			x;
	int			y;
	int			start;
	int			end;
	struct s_vertices	*next;
}				t_vertices;

typedef struct			s_edges
{
	char			*name1;
	char			*name2;
	struct s_edges		*next;
}				t_edges;

void				ft_add_to_list(t_lemin **list, char *line);
void				ft_print_initial_list(t_lemin *list);
void				ft_error_and_exit();
void				ft_create_graph_vertices_list(t_vertices **vertices, char *input);
void				ft_create_graph_edges_list(t_edges **edges, char *input);
void				ft_print_vertices_list(t_vertices *vertices);
void				ft_print_edges_list(t_edges *edges);

#endif
