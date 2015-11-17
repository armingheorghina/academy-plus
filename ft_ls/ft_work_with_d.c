/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 18:46:08 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/17 20:07:01 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_work_with_d(int i, int argc, char **argv)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				close_dir;
	t_ls_list		*start;
	struct stat		*buf;
	char			*lbuf;

	if (ft_get_file_type(i, argv) == 'd')
	{
		dirp = opendir(argv[i]);
		if (dirp != NULL)
		{
			start = NULL;
			while ((dp = readdir(dirp)) != NULL)
			{
				buf = (struct stat*)malloc(sizeof(*buf));
				(void)lstat(ft_strjoin(ft_strjoin(argv[i], "/"), dp->d_name), buf);
				lbuf = (char*)malloc(buf->st_size);
				(void)readlink(ft_strjoin(ft_strjoin(argv[i], "/"), dp->d_name), lbuf, buf->st_size);
				ft_push_sort_lsl(&start, dp->d_name, buf->st_size, buf->st_mtime, buf->st_uid, buf->st_gid, buf->st_nlink, buf->st_mode, buf->st_blocks, lbuf);
				if (dp == NULL) // *TODO move this 2 lines to top of while in all files
					perror("readdir error");
			}
			if (argc > 3)
			{
				ft_putstr(argv[i]);
				ft_putstr(":\n");
			}
			ft_delete_hidden_from_list(&start);
			ft_push_bsl_bnl_to_list(start);
			ft_push_buidl_bgidl_to_list(start);
			ft_putlist_lsl(start);
			// *TODO free list : use ft_lstdel(start, f_free_str)
			if (argc > 3 && i != argc - 1) // && ft_isflag(argc - 1, "-a", argv))
				ft_putchar('\n');
			close_dir = closedir(dirp);
			if (close_dir == -1)
				perror("closedir error");
		}
	}
}
