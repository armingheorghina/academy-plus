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

int	ft_str_is_alnum(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_str_is_digit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_line_is_a_valid_vertice(char *line)
{
	int i;
	char	**map;

	map = ft_strsplit(line, ' ');
	i = 0;
	while (map[i])
		i++;
	if (i != 3 || map[0][0] == 'L' || map[0][0] == '#')
		return (0);
	i = 0;
	while (map[0][i])
	{
		if (!ft_isalnum(map[0][i]))
			return (0);
		i++;
	}
	if (!ft_str_is_digit(map[1]) || !ft_str_is_digit(map[2]))
		return (0);
	return (1);
}
	
int	ft_line_is_a_valid_edge(char *line)
{
	char	*minus;
	char	*part1;
	char 	*part2;

	minus = ft_strchr(line, '-');
	if (minus == NULL)
		return (0);
	part1 = ft_strsub(line, 0, ft_strlen(line) - ft_strlen(minus));
	if (ft_strlen(part1) == 0)
		return (0);
	part2 = ft_strdup(minus + 1);
	if (ft_strlen(part2) == 0)
		return (0);
	if (!ft_str_is_alnum(part1) || !ft_str_is_alnum(part2))
		return (0);
	return (1);
}

int		ft_check_line(char *line, t_vertices **vertices, t_edges **edges)
{
	if (line[0] == '#' && line[1] != '#') //comentariu
		return (1);
	if (ft_strcmp("##start", line) == 0)
	{
		g_start = 1;
		return (1);
	}
	if (ft_strcmp("##end", line) == 0)
	{
		g_end = 1;
		return (1);
	}
	if (ft_strcmp("##start", line) != 0 && ft_strcmp("##end", line) != 0 &&
			line[0] == '#' && line[1] == '#') //comentariu - comanda necunoscuta 
		return (1);
	if (ft_line_is_a_valid_vertice(line))
	{
		ft_create_graph_vertices_list(vertices, line);
		return (1);
	}
	if (ft_line_is_a_valid_edge(line))
	{
		ft_create_graph_edges_list(edges, line);
		return (1);
	}
	return (0);
}

int		ft_validate_and_get_number_of_ants(char *line)
{
	int ants;
	int i;

	ants = 0;
	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			ft_error_and_exit();
		i++;
	}
	ants = ft_atoi(line);
	return (ants);
}

void	ft_validate_and_create_graph(t_lemin *list, t_vertices **vertices,
		t_edges **edges)
{
	t_lemin 	*start;
	int		ants;

	start = list;
	if (start == NULL)
		ft_error_and_exit();
	ants = ft_validate_and_get_number_of_ants(start->input_line);
	g_ants = ants;
	start = start->next;
	while (start)
	{
		if (ft_strcmp("\n", start->input_line) == 0) //linie goala - termina citirea
			return ;
		if (ft_check_line(start->input_line, vertices, edges) == 0) //linie neconforma - termina citirea
			return ;
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
	ft_print_initial_list(list);
	vertices = NULL;
	edges = NULL;
	ft_validate_and_create_graph(list, &vertices, &edges);
	ft_print_vertices_list(vertices); //working on
	if (!vertices || !edges)
		ft_error_and_exit();
	return (0);
}
