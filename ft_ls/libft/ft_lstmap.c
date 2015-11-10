/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 18:26:47 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/02 14:58:06 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*last;

	last = f(lst);
	new = last;
	if (new == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		last->next = f(lst);
		if (last->next == NULL)
			return (NULL);
		last = last->next;
	}
	return (new);
}
