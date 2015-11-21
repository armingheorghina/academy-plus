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

void	ft_work_with_f(int i, char **argv, char *flag)
{
	struct stat			*buf;
	static t_ls_list	*start = NULL;
	char				*lbuf;

	if	(ft_get_file_type(i, argv) == '-')
	{

		buf = (struct stat*)malloc(sizeof(*buf));
		(void)lstat((argv[i]), buf);
		lbuf = ft_strdup("");
		ft_push_sort_lsl0(&start, argv[i], buf->st_blocks, lbuf);
		ft_push_sort_lsl2(start, argv[i], buf->st_size, buf->st_mtime);
		ft_push_sort_lsl3(start, argv[i], buf->st_uid, buf->st_gid);
		ft_push_sort_lsl4(start, argv[i], buf->st_nlink, buf->st_mode);
		ft_push_sort_lsl5(start, argv[i], listxattr(argv[i], NULL, 0, XATTR_NOFOLLOW), buf->st_atime);
		ft_push_bsl_bnl_to_list(start);
		ft_push_buidl_bgidl_to_list(start);
		ft_putlist_lsl(start, flag);
	//	if (ft_check_if_flag_contains(flag, 'l'))
	//	{
	//		ft_putmode(buf->st_mode, listxattr(argv[i], NULL, 0, XATTR_NOFOLLOW));
		//	ft_puthardlinks((int)buf->nlink, biggest_nlink_len);
	//		if (ft_check_if_flag_contains(flag, 'l') == 1 && ft_check_if_flag_contains(flag, 'g') == 0)
		//		ft_putuid_name(buf->st_uid, biggest_uid_len);
		//	ft_putgid_name(buf->st_gid, biggest_gid_len);
		//	ft_putbytes((int)buf->st_size, biggest_size_len);
				
	//		if (ft_check_if_flag_contains(flag, 'u') == 1)
	//			ft_puttime(ctime(&(buf->st_atime)));
	//		else
	//			ft_puttime(ctime(&(buf->st_mtime)));
	//		ft_putendl(argv[i]);
	//	}
	//	else
	//		ft_putendl(argv[i]);
	}
}	
