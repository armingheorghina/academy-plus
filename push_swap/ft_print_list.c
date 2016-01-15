#include "push_swap.h"

void	ft_print_list(t_pslist *list)
{
	t_pslist *start;

	start = list;
	while (start)
	{
		ft_putnbr(start->operation);
		ft_putchar(' ');
		start = start->next;
	}
	ft_putchar('\n');
}
