/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:52:13 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/27 17:09:27 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# define CONVERSIONS "sSpdDioOuUxXcC"
# define FLAGS "#0-+ jzhl123456789"

int		ft_printf(const char *format, ...);

char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strchr(const char *s, int c);

#endif
