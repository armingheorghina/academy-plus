/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 17:56:32 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/12 16:06:51 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <stdio.h>

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
