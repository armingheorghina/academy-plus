# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdruta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/02 16:35:04 by vdruta            #+#    #+#              #
#    Updated: 2015/11/14 01:08:58 by vdruta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = x.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	gcc -Wall -Werror -Wextra -I libft/ -c ft_ls_a.c
	gcc -o ft_ls_a ft_ls_a.o -L libft/ -lft
	gcc -Wall -Werror -Wextra -I libft/ -c ft_ls_r.c
	gcc -o ft_ls_r ft_ls_r.o -L libft/ -lft
	gcc -Wall -Werror -Wextra -I libft/ -c ft_ls_rm.c
	gcc -o ft_ls_rm ft_ls_rm.o -L libft/ -lft
	gcc -Wall -Werror -Wextra -I libft/ -c ft_inspect_file.c
	gcc -o ft_inspect_file ft_inspect_file.o -L libft/ -lft
	gcc -Wall -Werror -Wextra -I libft/ -c $(SRCS)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f ft_ls_a.o
	/bin/rm -f ft_ls_r.o
	/bin/rm -f ft_ls_rm.o
	/bin/rm -f ft_inspect_file.o
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f ft_ls_a
	/bin/rm -f ft_ls_r
	/bin/rm -f ft_ls_rm
	/bin/rm -f ft_inspect_file
	/bin/rm -f libft/libft.a

re: fclean all
