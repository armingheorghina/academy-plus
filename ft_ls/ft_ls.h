/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 17:56:32 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/16 17:13:33 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
//# include <uuid/uuid.h>
# include <grp.h>
# include <stdio.h>
# include <time.h>

typedef struct s_ls_list
{
	char				*name;				/* readdir - get dir name*/
	mode_t				mode;	 			/* stat - protection */
	nlink_t				nlink;				/* stat - number of hard links */
	int					biggest_nlink_len;	/* bigest nlink length*/
	uid_t				uid;	 			/* stat - user ID of owner */
	int					biggest_uid_len;
	gid_t				gid;	    		/* stat - group ID of owner */
	int					biggest_gid_len;
	off_t				bytes_size;			/* stat - total size, in bytes */
	int					biggest_size_len;	/* bigest bytes_size length */
	time_t   			mtime;				/* stat - time of last modification */
	struct s_ls_list	*next;
}t_ls_list;



#endif
/*
 * ◦ write
 * ◦ opendir
 DIR				*opendir(const char *filename);
 * ◦ readdir
 struct dirent	*readdir(DIR *dirp);
 * ◦ closedir
 int				closedir(DIR *dirp);
 * ◦ stat
 int				stat(const char *restrict path, struct stat *restrict buf);
 * ◦ lstat
 int				lstat(const char *restrict path, struct stat *restrict buf);
 * ◦ getpwuid
 struct passwd	*getpwuid(uid_t uid);
 * ◦ getgrgid
 struct group	*getgrgid(gid_t gid);
 * ◦ listxattr
 * ◦ getxattr
 * ◦ time
 * ◦ ctime
 * ◦ readlink
 * ◦ malloc
 * ◦ free
 * ◦ perror
 * ◦ strerror
 * ◦ exit
 * -l, -R, -a, -r
 *  si -t.
 * */
