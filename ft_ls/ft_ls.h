/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 17:56:32 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/18 18:32:36 by vdruta           ###   ########.fr       */
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
	blkcnt_t			blocks;				/* number of 512B blocks allocated */
	time_t   			mtime;				/* stat - time of last modification */
	char				*link_name;			/* readlink */				
	struct s_ls_list	*next;
}t_ls_list;

void	ft_work_with_e(int i, char **argv);
void	ft_work_with_d(int i, int argc, char **argv, char *flag);


char	ft_get_file_type(int i, char **argv);
void	ft_push_sort_lsl(t_ls_list **begin, char *str, blkcnt_t st_blocks, char *lbuf);
void	ft_push_sort_lsl2(t_ls_list *start, char *str, off_t size, time_t time);
void	ft_push_sort_lsl3(t_ls_list *start, char *str, uid_t st_uid, gid_t st_gid);
void	ft_push_sort_lsl4(t_ls_list *start, char *str, nlink_t st_nlink, mode_t st_mode);
void	ft_push_bsl_bnl_to_list(t_ls_list *start);
void	ft_puttime(char *str);
void	ft_push_bsl_bnl_to_list(t_ls_list *start);
void	ft_push_buidl_bgidl_to_list(t_ls_list *start);
void	ft_putbytes(int bytes_size, int biggest_size_len);
void	ft_putuid_name(struct passwd *pwd, int biggest_uid_len);
void	ft_putgid_name(struct group *grp, int biggest_gid_len);
void	ft_puthardlinks(int nlink, int biggest_nlink_len);
void	ft_putmode(mode_t mode);
void	ft_put_total(t_ls_list *start);
void	ft_putlink(char	*file_name, char *link_name);
void	ft_putlist_lsl(t_ls_list *start, char *flag);
void	ft_delete_hidden_from_list(t_ls_list **start);
int		ft_isflag(int i, char *flag, char **argv);
char	ft_get_file_type(int i, char **argv);
char	*ft_get_flag(int i, int argc, char **argv);
int		ft_get_flags_number(int i, int argc, char** argv);
int	ft_check_if_flag_contains(char *str, char c);
void	ft_sort_list_reverse(t_ls_list *start);
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
 *ssize_t
      readlink(const char *restrict path, char *restrict buf, size_t bufsize);
 * ◦ malloc
 * ◦ free
 * ◦ perror
 * ◦ strerror
 * ◦ exit
 * -l, -R, -a, -r
 *  si -t.
 * */
