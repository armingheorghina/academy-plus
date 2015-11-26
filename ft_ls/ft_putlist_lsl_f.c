/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlist_lsl_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:28:19 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/26 14:28:22 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putlist_lsl_f(t_ls_list *start, char *flag)
{
	time_t		local_time;

	local_time = time((time_t*)NULL);
	while (start)
	{
		
		if (ft_check_if_flag_contains(flag, 'l') == 1 || ft_check_if_flag_contains(flag, 'g') == 1)
		{
			ft_putmode(start->mode, start->xattr_nbr);
			ft_puthardlinks((int)start->nlink, start->biggest_nlink_len);
			if (ft_check_if_flag_contains(flag, 'l') == 1 && ft_check_if_flag_contains(flag, 'g') == 0)
				ft_putuid_name(start->uid, start->biggest_uid_len);
			ft_putgid_name(start->gid, start->biggest_gid_len);
			ft_putbytes((int)start->bytes_size, start->biggest_size_len);
				
			if (ft_check_if_flag_contains(flag, 'u') == 1)
			{
				if (ft_year_is_lower_than_1970(ctime(&(start->atime))))
					ft_putstr("Jan  1  10000 ");
				else
				{
					if (start->atime > local_time || start->atime < local_time - 15778463)
						ft_puttime_2(ctime(&(start->atime)));
					else
						ft_puttime(ctime(&(start->atime)));
				}
			}
			else
			{
				if (ft_year_is_lower_than_1970(ctime(&(start->mtime))))
					ft_putstr("Jan  1  10000 ");
				else
				{
					if (start->mtime > local_time || start->mtime < (local_time - 15778463))
						ft_puttime_2(ctime(&(start->mtime)));
					else
						ft_puttime(ctime(&(start->mtime)));
				}
			}
			if (S_ISLNK(start->mode) == 1)
				ft_putlink(start->name, start->link_name);
			else
				ft_putendl(start->name);
		}
		else
			ft_putendl(start->name);
		start = start->next;
	}
}
