/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:52:13 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/15 19:55:13 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <inttypes.h>
# include <sys/types.h>
# include <string.h>
# define CONVERSIONS "sSpdDioOuUxXcCfF"
# define FLAGS "#0-+ jzhl123456789.*"

#include <stdio.h> //*TODO delete this!

long long		g_nbr;
typedef struct	s_arg
{
	int			precision;
	int			width;
	int			flag_hash;
	int			flag_zero;
	int			flag_minus;
	int			flag_plus;
	int			flag_space;
	int			lm_j;
	int			lm_z;
	int			lm_h;
	int			lm_hh;
	int			lm_l;
	int			lm_ll;
}				t_arg;


int				ft_printf(const char *format, ...);
int		ft_is_a_valid_descriptor(const char *str);
int		ft_descriptor_len(const char *format);
void	ft_initialize_flags_and_lm(t_arg *arg);
void	ft_process_c_uc(va_list ap, int *bytes, t_arg arg);
void	ft_process_c_width(unsigned char c, int *bytes, t_arg arg);
void	ft_process_c_flag_zero(unsigned char c, int *bytes, t_arg arg);
void	ft_process_c_flag_minus(unsigned char c, int *bytes, t_arg arg);
void	ft_process_s_precision(char **str, t_arg arg);
void	ft_process_o_lm_j(va_list ap, int *bytes, char *descriptor, t_arg arg);
void	ft_process_x_no_lm(va_list ap, int *bytes, char *descriptor, t_arg arg);
void	ft_process_xx_lm_l(va_list ap, int *bytes, char *descriptor, t_arg arg);
void	ft_process_xx_lm_z(va_list ap, int *bytes, char *descriptor, t_arg arg);
int				ft_isalpha(int c);
char			*ft_strdup(const char *s1);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memalloc(size_t size);
char			*ft_itoa(int n);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			ft_putchar(char c);
void			ft_putwchar(wchar_t wc);
int				ft_wcharsize(wchar_t wc);
wchar_t			*ft_wstrsub(wchar_t *s, unsigned int start, size_t len);
int				ft_wstrsize(wchar_t *wstr);
wchar_t			*ft_wstrdup(const wchar_t *s1);
wchar_t			*ft_wstrjoin(wchar_t const *s1, wchar_t const *s2);
int				ft_wstrlen(const wchar_t *s);
wchar_t			*ft_wmemset(wchar_t *b, wchar_t c, size_t len);
void			ft_putstr(char const *s);
int				ft_strlen(const char *s);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
void			ft_putnbr(int n);
char			*ft_itoabase(uintmax_t val, int base);
char			*ft_itoabbase(uintmax_t val, int base);
char			*ft_short_to_ascii_base(short val, int base);
char			*ft_long_to_ascii_base(long val, int base);
char			*ft_long_long_to_ascii_base(long long val, int base);
char			*ft_unsigned_short_to_ascii_base(unsigned short val, int base);
char			*ft_unsigned_int_to_ascii_base(unsigned int val, int base);
char			*ft_unsigned_long_to_ascii_base(unsigned long val, int base);
char			*ft_unsigned_long_long_to_ascii_base(unsigned long long val, int base);
char			*ft_int_to_ascii_base(int val, int base);
char			*ft_intmax_t_to_ascii_base(intmax_t val, int base);
char			*ft_ssize_t_to_ascii_base(ssize_t val, int base);
char			*ft_size_t_to_ascii_base(size_t val, int base);
char			*ft_uintmax_t_to_ascii_base(uintmax_t val, int base);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_ftoa(double val, int precision);
char			*ft_process_p_width(char *str, t_arg arg);
void			ft_process_d_put_flag_plus(int *bytes, char **str, t_arg arg);
void			ft_process_d_put_flag_space(int *bytes, char **str, t_arg arg);
char			*ft_process_d_precision(char *str, t_arg arg);
char			*ft_process_d_width(char *str, t_arg arg);
void			ft_process_percent_width(char **str, t_arg arg);
void			ft_process_s_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void			ft_process_ss_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void			ft_process_d_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void			ft_process_dd_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void			ft_process_p_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void			ft_process_c_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void			ft_process_cc_(va_list ap, int *bytes);
void			ft_process_o_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void			ft_process_oo_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void			ft_process_u_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void			ft_process_uu_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void			ft_process_x_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void			ft_process_xx_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void			ft_process_percent_(int *bytes, t_arg arg);
void			ft_process_non_valid_conversion_(int *bytes, char *descriptor, t_arg arg);
void			ft_process_f_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void	ft_process_d_short(va_list ap, int *bytes, char *descriptor, t_arg arg);
#endif
