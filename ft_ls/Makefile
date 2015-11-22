# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdruta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/02 16:35:04 by vdruta            #+#    #+#              #
#    Updated: 2015/11/21 16:42:21 by vdruta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_ls

SRCS = ft_ls.c ft_work_with_d.c ft_work_with_e.c ft_work_with_f.c ft_push_sort_lsl_f.c ft_push_sort_lsl0_f.c ft_push_sort_lsl2_f.c ft_push_sort_lsl3_f.c ft_push_sort_lsl4_f.c ft_push_sort_lsl5_f.c ft_push_bsl_bnl_to_list_f.c ft_push_buidl_bgidl_to_list_f.c ft_put_list_lsl_f.c

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
