# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdruta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/02 16:35:04 by vdruta            #+#    #+#              #
#    Updated: 2015/11/28 17:27:29 by vdruta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a


SRCS = ft_printf.c ft_itoa.c ft_putchar.c ft_putstr.c ft_strlen.c ft_strsub.c \
		ft_strchr.c ft_putnbr.c ft_process_s_.c ft_process_d_.c \
		ft_process_c_.c ft_process_o_.c ft_itoabase.c ft_process_u_.c \
		ft_process_x_.c ft_process_X_.c ft_itoaBase.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	gcc -Wall -Werror -Wextra -c main.c
	gcc -o ft_printf main.o -L. -lftprintf

clean:
	/bin/rm -f $(OBJS)
	/bin/rm -f main.o

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f ft_printf

re: fclean all
