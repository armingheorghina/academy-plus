#include "libft.h"

t_uclist	*ft_uclistnew(unsigned char value)
{
	t_uclist	*new;

	new = malloc(sizeof(t_uclist));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = value;
	return (new);
}
