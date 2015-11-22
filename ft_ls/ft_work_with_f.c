/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 16:03:14 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/21 19:05:31 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls_list_f	*ft_work_with_f(int i, char **argv, char *flag)
{
	struct stat		*buf;
	static t_ls_list_f	*start = NULL;
	char			*lbuf;

	if	(ft_get_file_type(i, argv) == '-')
	{

		buf = (struct stat*)malloc(sizeof(*buf));
		(void)lstat((argv[i]), buf);
		lbuf = ft_strdup("");
		if (ft_check_if_flag_contains(flag, 't') == 1 || ft_check_if_flag_contains(flag, 'f') == 1)
		{
			ft_push_sort_lsl0_f(&start, argv[i], buf->st_blocks, lbuf);
			ft_push_sort_lsl2_f(start, argv[i], buf->st_size, buf->st_mtime);
			ft_push_sort_lsl3_f(start, argv[i], buf->st_uid, buf->st_gid);
			ft_push_sort_lsl4_f(start, argv[i], buf->st_nlink, buf->st_mode);
			ft_push_sort_lsl5_f(start, argv[i], listxattr(argv[i], NULL, 0), buf->st_atime);
		}
		else	/* sort by ascii*/
		{
			ft_push_sort_lsl_f(&start, argv[i], buf->st_blocks, lbuf);
			ft_push_sort_lsl2_f(start, argv[i], buf->st_size, buf->st_mtime);
			ft_push_sort_lsl3_f(start, argv[i], buf->st_uid, buf->st_gid);
			ft_push_sort_lsl4_f(start, argv[i], buf->st_nlink, buf->st_mode);
			ft_push_sort_lsl5_f(start, argv[i], listxattr(argv[i], NULL, 0), buf->st_atime);
		}
	}
	return (start);
}	
