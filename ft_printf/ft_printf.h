/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:52:13 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/07 12:59:52 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <inttypes.h>
#include <sys/types.h>
# define CONVERSIONS "sSpdDioOuUxXcC"
# define FLAGS "#0-+ jzhl123456789."

typedef struct		s_arg
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
}					t_arg;

int		ft_printf(const char *format, ...);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memalloc(size_t size);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putchar(char c);
void	ft_putwchar(wchar_t wc);
int		ft_wcharsize(wchar_t wc);
void	ft_putstr(char const *s);
int	ft_strlen(const char *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	ft_putnbr(int n);
char	*ft_itoabase(uintmax_t val, int base);
char	*ft_itoabbase(uintmax_t val, int base);
char	*ft_short_to_ascii_base(short val, int base);
char	*ft_long_long_to_ascii_base(long long val, int base);
char	*ft_unsigned_short_to_ascii_base(unsigned short val, int base);
char	*ft_unsigned_int_to_ascii_base(unsigned int val, int base);
char	*ft_unsigned_long_to_ascii_base(unsigned long val, int base);
char	*ft_unsigned_long_long_to_ascii_base(unsigned long long val, int base);
char	*ft_int_to_ascii_base(int val, int base);
char	*ft_intmax_t_to_ascii_base(intmax_t val, int base);
char	*ft_ssize_t_to_ascii_base(ssize_t val, int base);
char	*ft_size_t_to_ascii_base(size_t val, int base);
char	*ft_uintmax_t_to_ascii_base(uintmax_t val, int base);
char	*ft_strjoin(const char *s1, const char *s2);

void	ft_process_s_(va_list ap, int *bytes, t_arg arg);
void	ft_process_ss_(va_list ap, int *bytes);
void	ft_process_d_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void	ft_process_dd_(va_list ap, int *bytes, t_arg arg);
void	ft_process_p_(va_list ap, int *bytes);
void	ft_process_c_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void	ft_process_cc_(va_list ap, int *bytes);
void	ft_process_o_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void	ft_process_oo_(va_list ap, int *bytes, t_arg arg);
void	ft_process_u_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void	ft_process_uu_(va_list ap, int *bytes);
void	ft_process_x_(va_list ap, int *bytes, char *descriptor, t_arg arg);
void	ft_process_xx_(va_list ap, int *bytes, char *descriptor, t_arg arg);


#endif
