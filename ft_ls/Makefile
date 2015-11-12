# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdruta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/02 16:35:04 by vdruta            #+#    #+#              #
#    Updated: 2015/11/12 11:43:15 by vdruta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

NAME2 = ft_list_dir

SRCS = x.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	gcc -Wall -Werror -Wextra -I libft/ -c ft_list_dir.c
	gcc -o $(NAME2) ft_list_dir.o -L libft/ -lft
	gcc -Wall -Werror -Wextra -I libft/ -c $(SRCS)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f ft_list_dir.o
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME2)
	/bin/rm -f libft/libft.a

re: fclean all
