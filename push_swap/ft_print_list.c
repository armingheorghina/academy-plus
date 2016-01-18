#include "push_swap.h"
void	ft_putstr_space(char *str)
{
	ft_putstr(str);
	ft_putchar(' ');
}

void	ft_print_list(t_pslist *list)
{
	t_pslist *start;

	start = list;
	while (start)
	{
		if (start->operation == 1 && (start->next)->operation == 2)
		{
			ft_putstr_space("ss");
			start = start->next;
		}
		else if (start->operation == 1)
			ft_putstr_space("sa");
		else if (start->operation == 2)
			ft_putstr_space("sb");
		else if (start->operation == 4)
			ft_putstr_space("pa");
		else if (start->operation == 5)
			ft_putstr_space("pb");
		else if (start->operation == 6 && (start->next)->operation == 7)
		{
			ft_putstr_space("rr");
			start = start->next;
		}
		else if (start->operation == 6)
			ft_putstr_space("ra");
		else if (start->operation == 7)
			ft_putstr_space("rb");
		else if (start->operation == 9 && (start->next)->operation == 10)
		{
			ft_putstr_space("rrr");
			start = start->next;
		}
		else if (start->operation == 9)
			ft_putstr_space("rra");
		else if (start->operation == 10)
			ft_putstr_space("rrb");
		start = start->next;
	}
	ft_putchar('\n');
}
