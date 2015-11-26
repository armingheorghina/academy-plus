# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdruta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/02 16:35:04 by vdruta            #+#    #+#              #
#    Updated: 2015/11/26 18:21:21 by vdruta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	gcc -Wall -Werror -Wextra -I libft/ -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	gcc -Wall -Werror -Wextra -I libft/ -c main.c ft_printf.c
	gcc -o ft_printf main.o ft_printf.o -L libft/ -lft

clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean
	/bin/rm -f main.o

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f libft/libft.a
	/bin/rm -f ft_printf

re: fclean all
