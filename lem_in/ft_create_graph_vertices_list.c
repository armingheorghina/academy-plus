/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_graph_vertices_list.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:51:07 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/17 19:31:12 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_create_graph_edges_list(t_edges **edges, char *input)
{
	t_edges	*new;
	t_edges	*start;
	char	*minus;

	
	new = (t_edges*)malloc(sizeof(*new));
	minus = ft_strchr(input, '-');

	new->name1 = ft_strsub(input, 0 , ft_strlen(input) - ft_strlen(minus));
	new->name2 = ft_strdup(minus + 1);
	new->next = NULL;
	start = *edges;
	if (start == NULL)
		*edges = new;
	else
	{
		while (start->next)
			start = start->next;
		start->next = new;
	}

}

void	ft_create_graph_vertices_list(t_vertices **vertices, char *input)
{
	t_vertices	*new;
	t_vertices	*start;
	char		**map;
	static int		cnt = 0;

	map = ft_strsplit(input, ' ');
	new = (t_vertices*)malloc(sizeof(*new));
	new->id = cnt;
	new->name = map[0];
	new->x = ft_atoi(map[1]);
	new->y = ft_atoi(map[2]);
	new->start = g_start;
	g_start = 0;
	new->end = g_end;
	g_end = 0;
	new->next = NULL;
	start = *vertices;
	if (start == NULL)
		*vertices = new;
	else
	{
		while (start->next)
			start = start->next;
		start->next = new;
	}
	cnt++;
}
