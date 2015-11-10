# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdruta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/02 16:35:04 by vdruta            #+#    #+#              #
#    Updated: 2015/11/10 17:56:24 by vdruta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = *.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	gcc -Wall -Werror -Wextra -I libft/ -c $(SRCS)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f libft/libft.a

re: fclean all
