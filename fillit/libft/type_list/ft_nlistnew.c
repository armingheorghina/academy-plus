#include "libft.h"

t_nlist	*ft_nlistnew(int value)
{
	t_nlist	*new;

	new = malloc(sizeof(t_nlist));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = value;
	return (new);
}
