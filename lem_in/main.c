/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:07:51 by vdruta            #+#    #+#             */
/*   Updated: 2016/02/08 18:52:28 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_line_is_a_valid_vertice(char *line)
{
	int i;
	int j;
	int space;
	int numbers;

	i = 0;
	space = 0;
	numbers = 0;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			space++;
			j = i;
			j++;
			if (ft_isdigit(line[j]))
				numbers++;
			while (line[j] || line[j] != ' ')
			{
				if (!ft_isdigit(line[j]))
					ft_error_and_exit();
				j++;
			}
		}
		i++;
	}
	if (space != 2 || numbers != 2)
		return (0);
	if (line[0] == 'L')
		return (0);
	return (1);
}

int		ft_check_line(char *line)
{
	int i;

	if (line[0] == '#' && line[1] != '#') //comentariu
		return ;
	else if (ft_strcmp("##start", line) == 0)
		g_start = 1;
	else if (ft_strcmp("##end", line) == 0)
		g_end = 1;
	else if (ft_strcmp("##start", line) != 0 && ft_strcmp("##end", line) != 0 &&
			line[0] == '#' && line[1] == '#') //comanda necunoscuta
		return ;
	else if (ft_line_is_a_valid_vertice(line))
		return (1);
	else if (ft_line_is_a_valid_edge(line))
		return (2);
	return (0);
}

int		ft_get_number_of_ants(char *line)
{
	int ants;
	int i;

	ants = 0;
	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error_and_exit();
		i++;
	}
	ants = ft_atoi(line);
	return (ants)
}

void	ft_validate_and_create_graph(t_lemin *list, t_vertices **vertices,
		t_edges, **edges)
{
	t_lemin start;
	int		ants;

	start = list;
	ants = ft_validate_and_get_number_of_ants(start->input_line);
	start = start->next;
	while (start)
	{
		if (ft_strcmp("\n", start->input_line) == 0) //linie goala
			return ;
		else if (ft_check_line(list->input_line) == 0) //linie neconforma
			return ;
		else if (ft_check_line(list->input_line) == 1)
			ft_create_graph_vertices_list(vertices, list->input_line);
		else if (ft_check_line(list->input_line) == 2)
			ft_create_graph_edges_list(edges, list->input_line);
		start = start->next;
	}
}

int		main()
{
	char		*line;
	t_lemin		*list;
	t_vertices	*vertices;
	t_edges		*edges;

	list = NULL;
	while(ft_get_next_line(0, &line))
		ft_add_to_list(&list, line);
	//ft_print_initial_list(list);
	vertices = NULL;
	edges = NULL;
	ft_validate_and_create_graph(list, &vertices, &edges);
	if (vertices == NULL || edges == NULL)
		ft_error_and_exit();
	return (0);
}
