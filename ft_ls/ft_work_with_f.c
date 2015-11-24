/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 16:03:14 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/24 11:52:37 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls_list	*ft_work_with_f(int i, char **argv, char *flag)
{
	struct stat		*buf;
	static t_ls_list	*start = NULL;
	char			*lbuf;

	if	(ft_get_file_type(i, argv) == '-')
	{
		if (ft_first_valid_directory_target() == 0) // if targets contains dirs and files.
			ft_putchar('c');
		buf = (struct stat*)malloc(sizeof(*buf));
		(void)lstat((argv[i]), buf);
		lbuf = ft_strdup("");
		if (ft_check_if_flag_contains(flag, 't') == 1 || ft_check_if_flag_contains(flag, 'f') == 1)
		{
			ft_push_sort_lsl0(&start, argv[i], buf->st_blocks, lbuf);
			ft_push_sort_lsl2(start, argv[i], buf->st_size, buf->st_mtime);
			ft_push_sort_lsl3(start, argv[i], buf->st_uid, buf->st_gid);
			ft_push_sort_lsl4(start, argv[i], buf->st_nlink, buf->st_mode);
			ft_push_sort_lsl5(start, argv[i], listxattr(argv[i], NULL, 0, XATTR_NOFOLLOW), buf->st_atime);
		}
		else	/* sort by ascii*/
		{
			ft_push_sort_lsl(&start, argv[i], buf->st_blocks, lbuf);
			ft_push_sort_lsl2(start, argv[i], buf->st_size, buf->st_mtime);
			ft_push_sort_lsl3(start, argv[i], buf->st_uid, buf->st_gid);
			ft_push_sort_lsl4(start, argv[i], buf->st_nlink, buf->st_mode);
			ft_push_sort_lsl5(start, argv[i], listxattr(argv[i], NULL, 0, XATTR_NOFOLLOW), buf->st_atime);
		}
	/*	if (ft_check_if_flag_contains(flag, 't') == 1 && ft_check_if_flag_contains(flag, 'u') == 1)
		{
			ft_sort_list_by_atime(start);
			ft_sort_list_by_ascii_for_atime_equal(start);
		}
		else if (ft_check_if_flag_contains(flag, 't') == 1)
		{
			ft_sort_list_by_mtime(start);
			ft_sort_list_by_ascii_for_mtime_equal(start);
		}
	*/	ft_push_bsl_bnl_to_list(start);
		ft_push_buidl_bgidl_to_list(start);
	}
	return (start);
}	
