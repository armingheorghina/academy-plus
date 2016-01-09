#include "libft.h"

void	ft_nlistadd(t_nlist **begin, t_nlist *new)
{
	new->next = *begin;
	*begin = new;
}
