/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 16:03:14 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/25 14:12:16 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
int			ft_special_case_link_to_dir(void)
{
	static int x = 0;

	x++;
	return (x);
}

t_ls_list	*ft_work_with_f(int i, char **argv, char *flag)
{
	struct stat			*buf;
	static t_ls_list	*start = NULL;
	char				*lbuf;
	int					readlink_return;

	if	(ft_get_file_type(i, argv) == '-' || ft_get_file_type(i, argv) == 'l' || ft_get_file_type(i, argv) == 'c' || ft_get_file_type(i, argv) == 'b'|| ft_get_file_type(i, argv) == 'f' || ft_get_file_type(i, argv) == 's' || (ft_get_file_type(i, argv) == 'd' && ft_check_if_flag_contains(flag, 'd') == 1))
	{

		buf = (struct stat*)malloc(sizeof(*buf));
		(void)lstat((argv[i]), buf);
		if (S_ISLNK(buf->st_mode) == 1)
		{
			lbuf = (char*)malloc(1024);
			readlink_return = readlink(argv[i], lbuf, 1024);
			lbuf[readlink_return] = '\0';
			
			if (ft_get_file_type_2(lbuf) == 'd' && ft_check_if_flag_contains(flag, 'l') == 0)
				return (NULL);
		}
		else
			lbuf = ft_strdup("");
		

		if (ft_first_valid_directory_target() == 0) // if targets contains dirs and files. can't be 0 :) for print
			ft_putchar('c');


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
	}
	return (start);
}	
