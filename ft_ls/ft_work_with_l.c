/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:21:26 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/24 17:31:32 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_work_with_l(int i, char **argv, char *flag) // *TODO find a way to print corectly when -l is not present!
{
	struct stat			*buf;
	char				*lbuf;
	int					readlink_return;

	if	(ft_get_file_type(i, argv) == 'l' && ft_check_if_flag_contains(flag, 'l') == 0)
	{
		buf = (struct stat*)malloc(sizeof(*buf));
		(void)lstat((argv[i]), buf);
		lbuf = (char*)malloc(1024);
		readlink_return = readlink(argv[i], lbuf, 1024);
		lbuf[readlink_return] = '\0';
		if (ft_check_if_flag_contains(flag, 'l') == 0)
			ft_work_with_d(lbuf, flag);
		ft_work_with_f(i, argv, flag);
/*		if (ft_check_if_flag_contains(flag, 't') == 1 || ft_check_if_flag_contains(flag, 'f') == 1)
		{
			ft_push_sort_lsl0(&start, argv[i], buf->st_blocks, lbuf);
			ft_push_sort_lsl2(start, argv[i], buf->st_size, buf->st_mtime);
			ft_push_sort_lsl3(start, argv[i], buf->st_uid, buf->st_gid);
			ft_push_sort_lsl4(start, argv[i], buf->st_nlink, buf->st_mode);
			ft_push_sort_lsl5(start, argv[i], listxattr(argv[i], NULL, 0, XATTR_NOFOLLOW), buf->st_atime);
		}
		else	
		{
			ft_push_sort_lsl(&start, argv[i], buf->st_blocks, lbuf);
			ft_push_sort_lsl2(start, argv[i], buf->st_size, buf->st_mtime);
			ft_push_sort_lsl3(start, argv[i], buf->st_uid, buf->st_gid);
			ft_push_sort_lsl4(start, argv[i], buf->st_nlink, buf->st_mode);
			ft_push_sort_lsl5(start, argv[i], listxattr(argv[i], NULL, 0, XATTR_NOFOLLOW), buf->st_atime);
		}
		if (ft_check_if_flag_contains(flag, 't') == 1 && ft_check_if_flag_contains(flag, 'u') == 1)
		{
			ft_sort_list_by_atime(start);
			ft_sort_list_by_ascii_for_atime_equal(start);
		}
		else if (ft_check_if_flag_contains(flag, 't') == 1)
		{
			ft_sort_list_by_mtime(start);
			ft_sort_list_by_ascii_for_mtime_equal(start);
		}
		if (ft_check_if_flag_contains(flag, 'r') == 1)
			ft_sort_list_reverse(start, flag);
		ft_push_bsl_bnl_to_list(start);
		ft_push_buidl_bgidl_to_list(start);
		
		if (S_ISLNK(buf->st_mode) == 1)
			start = NULL;
		*/
	}
}	
