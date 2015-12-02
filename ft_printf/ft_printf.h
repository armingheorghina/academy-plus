/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:52:13 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/02 13:01:22 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# define CONVERSIONS "sSpdDioOuUxXcC"
# define FLAGS "#0-+ jzhl123456789"

int		ft_printf(const char *format, ...);

char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putwchar(wchar_t wc);
int		ft_wcharsize(wchar_t wc);
void	ft_putstr(char const *s);
size_t	ft_strlen(const char *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	ft_putnbr(int n);
char	*ft_itoabase(unsigned long long val, int base);
char	*ft_itoabbase(unsigned long long val, int base);
char	*ft_strjoin(const char *s1, const char *s2);

void	ft_process_s_(va_list ap, int *bytes);
void	ft_process_ss_(va_list ap, int *bytes);
void	ft_process_d_(va_list ap, int *bytes);
void	ft_process_dd_(va_list ap, int *bytes);
void	ft_process_p_(va_list ap, int *bytes);
void	ft_process_c_(va_list ap, int *bytes);
void	ft_process_cc_(va_list ap, int *bytes);
void	ft_process_o_(va_list ap, int *bytes);
void	ft_process_oo_(va_list ap, int *bytes);
void	ft_process_u_(va_list ap, int *bytes);
void	ft_process_uu_(va_list ap, int *bytes);
void	ft_process_x_(va_list ap, int *bytes);
void	ft_process_xx_(va_list ap, int *bytes);


#endif
