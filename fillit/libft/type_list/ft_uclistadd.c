#include "libft.h"

void	ft_uclistadd(t_uclist **begin, t_uclist *new)
{
	new->next = *begin;
	*begin = new;
}
