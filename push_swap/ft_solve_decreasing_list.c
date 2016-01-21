#include "push_swap.h"

void	ft_solve_decreasing_list(int *l_a, t_pslist **ops, int *l_b)
{
	int items;

	items = g_aitems;
	while (!ft_l_a_is_complete_and_sorted(l_a, items))
	{
		if (g_aitems == 3)
		{
			ft_rotate_first_to_end(l_a);
			ft_add_to_list(ops, 6);
			ft_swap(l_a);
			ft_add_to_list(ops, 1);
			
		}
		while (!ft_l_a_is_sorted(l_a))
		{
			while (g_aitems > 4)
			{
				ft_pushb(l_b, l_a);
				ft_add_to_list(ops, 5);
			}
			ft_swap(l_a);
			ft_add_to_list(ops, 1);
			ft_rotate_first_to_end(l_a);
			ft_add_to_list(ops, 6);
			ft_rotate_first_to_end(l_a);
			ft_add_to_list(ops, 6);
			ft_swap(l_a);
			ft_add_to_list(ops, 1);
		}
		if (!ft_l_a_is_complete_and_sorted(l_a, items))
		{
			ft_push(l_a, l_b);
			ft_add_to_list(ops, 4);
			ft_rotate_first_to_end(l_a);
			ft_add_to_list(ops, 6);
		}
	}
}

int	ft_l_a_is_sorted_decreasing(int *l_a)
{
	int i;
	int start;

	i = 0;
	start = l_a[0];
	while (i < g_aitems)
	{
		if (l_a[i] > start)
			return (0);
		start = l_a[i];
		i++;
	}
	return (1);
}


