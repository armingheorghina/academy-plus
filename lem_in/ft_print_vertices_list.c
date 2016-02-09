#include "lem_in.h"

void	ft_print_vertices_list(t_vertices *vertices)
{
	t_vertices	*start2;

	start2 = vertices;
	while (start2)
	{
		ft_putstr(start2->name);
		ft_putchar(' ');
		ft_putchar('[');
		ft_putnbr(start2->x);
		ft_putchar(']');
		ft_putchar(' ');
		ft_putchar('[');
		ft_putnbr(start2->y);
		ft_putchar(']');
		ft_putchar(' ');
		ft_putstr("start:");
		ft_putnbr(start2->start);
		ft_putchar(' ');
		ft_putstr("end:");
		ft_putnbr(start2->end);
		ft_putchar('\n');
		start2 = start2->next;
	}
}
