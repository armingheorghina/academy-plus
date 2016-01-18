
#include "push_swap.h"

int	ft_find_second_small_number(int *l_a, int aitems)
{
	int *copy;
	int i;
	int temp;

	copy = (int*)malloc(sizeof(*copy) * (aitems));
	i = 0;
	while (i < aitems)
	{
		copy[i] = l_a[i];
		i++;
	}
	copy = ft_bubble_sort(copy, aitems);
	temp = copy[1];
	free(copy);
	return (temp);
}

void	ft_execute_route_2(int *l_a, int *aitems, t_pslist **ops, int *l_b, int *bitems)
{
	int small;
	int i;
	int next;
	int j;
	int ok;

	small = ft_find_smallest_number(l_a, *aitems);
	next = ft_find_second_small_number(l_a, *aitems);
	ok = 0;
	while (!ft_smallest_is_first(l_a, *aitems))
	{
		if (ft_next_is_route_formation())
		ft_rotate_first_to_end(l_a, *aitems);
		ft_add_to_list(ops, 6);
	}
	
	ft_push(l_b, bitems, l_a, aitems);
	ft_add_to_list(ops, 5);
}
