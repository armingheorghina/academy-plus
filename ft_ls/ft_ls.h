/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 17:56:32 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/26 14:21:04 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <stdio.h>
# include <time.h>
# include <sys/xattr.h>

int		g_targets_number;

typedef struct			s_ls_list
{
	char				*name;				
	mode_t				mode;	 			
	nlink_t				nlink;				
	int					biggest_nlink_len;	
	uid_t				uid;	 			
	int					biggest_uid_len;
	gid_t				gid;	    		
	int					biggest_gid_len;
	off_t				bytes_size;			
	int					biggest_size_len;	
	blkcnt_t			blocks;				
	time_t   			mtime;				
	time_t   			atime;				
	char				*link_name;						
	ssize_t				xattr_nbr;				
	struct s_ls_list	*next;
}						t_ls_list;

void					ft_work_with_e(int i, char **argv);
void					ft_work_with_d(char *path, char *flag);
t_ls_list				*ft_work_with_f(int i, char **argv, char *flag);
char					ft_get_file_type(int i, char **argv);
char					ft_get_file_type_2(char *path);
void					ft_push_sort_lsl(t_ls_list **begin, char *str, blkcnt_t st_blocks, char *lbuf);
void					ft_push_sort_lsl0(t_ls_list **begin, char *str, blkcnt_t st_blocks, char *lbuf);
void					ft_push_sort_lsl2(t_ls_list *start, char *str, off_t size, time_t time);
void					ft_push_sort_lsl3(t_ls_list *start, char *str, uid_t st_uid, gid_t st_gid);
void					ft_push_sort_lsl4(t_ls_list *start, char *str, nlink_t st_nlink, mode_t st_mode);
void					ft_push_sort_lsl5(t_ls_list *start, char *str, ssize_t xattr, time_t time);
void					ft_push_bsl_bnl_to_list(t_ls_list *start);
void					ft_puttime(char *str);
void					ft_puttime_2(char *str);
void					ft_push_buidl_bgidl_to_list(t_ls_list *start);
void					ft_putbytes(int bytes_size, int biggest_size_len);
void					ft_putuid_name(uid_t uid, int biggest_uid_len);
void					ft_putgid_name(gid_t gid, int biggest_gid_len);
void					ft_puthardlinks(int nlink, int biggest_nlink_len);
void					ft_putmode(mode_t mode, ssize_t xattr_nbr);
void					ft_put_total(t_ls_list *start);
void					ft_putlink(char	*file_name, char *link_name);
void					ft_putlist_lsl(t_ls_list *start, char *flag);
void					ft_putlist_lsl_f(t_ls_list *start, char *flag);
void					ft_delete_hidden_from_list(t_ls_list **start);
void					ft_delete_duplicates_from_list(t_ls_list **start);
int						ft_isflag(int i, char *flag, char **argv);
char					ft_get_file_type(int i, char **argv);
char					*ft_get_flag(int i, int argc, char **argv);
int						ft_get_flags_number(int i, int argc, char** argv);
int						ft_check_if_flag_contains(char *str, char c);
void					ft_sort_list_reverse(t_ls_list *start, char *flag);
void					ft_sort_list_by_mtime(t_ls_list *start);
void					ft_sort_list_by_atime(t_ls_list *start);
void					ft_sort_list_by_bytes_size(t_ls_list *start);
void					ft_sort_list_by_ascii_for_mtime_equal(t_ls_list *start);
void					ft_sort_list_by_ascii_for_atime_equal(t_ls_list *start);
void					ft_sort_list_by_ascii_for_bytes_size_equal(t_ls_list *start);
char					*ft_enable_flag_a(char *str, char c);
int						ft_first_valid_directory_target(void);
void					ft_directories_job(int i, int argc, char **argv, char *flag);
void					ft_strswap(char **str1, char **str2);
int						ft_special_case_link_to_dir(void);
int						ft_year_is_lower_than_1970(char *str);
#endif
