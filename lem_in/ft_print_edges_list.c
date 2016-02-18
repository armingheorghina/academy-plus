#include "lem_in.h"

void	ft_print_edges_list(t_edges *edges)
{
	t_edges *start;
	
	start = edges;
	while (start)
	{
		ft_putstr(start->name1);
		ft_putstr(" - ");
		ft_putstr(start->name2);
		ft_putchar('\n');
		start = start->next;
	}


}
