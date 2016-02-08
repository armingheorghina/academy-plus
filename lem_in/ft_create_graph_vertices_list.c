/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_graph_vertices_list.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:51:07 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/08 18:52:26 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_get_vertice_name(char *str)
{
	char *name;
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
}
/*
void	ft_create_graph_edges_list(t_edges **edges, char *input)
{
	t_edges	*new;
	t_edges	*start;
	
	new = (t_edges*)malloc(sizeof(*new));
	new->name1 = ft_get_edges_name(input);
	new->name2 = ft_get_edges_name(input);
}
*/
void	ft_create_graph_vertices_list(t_vertices **vertices, char *input)
{
	t_vertices	*new;
	t_vertices	*start;

	new = (t_vertices*)malloc(sizeof(*new));
	new->name = ft_get_vertice_name(input);
	new->x = ft_get_coordinate_x(input);
	new->y = ft_get_coordinate_y(input);
	new->start = g_start;
	g_start = 0;
	new->end = g_end;
	g_end = 0;
	new->next = NULL;
	start = *list;
	if (start == NULL)
		*list = new;
	else
	{
		while (start->next)
			start = start->next;
		start->next = new;
	}
}
