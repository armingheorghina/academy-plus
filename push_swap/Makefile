# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdruta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/02 16:35:04 by vdruta            #+#    #+#              #
#    Updated: 2016/01/22 15:02:21 by vdruta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ft_add_parameters_to_l_a.c ft_add_to_list.c ft_bubble_sort.c \
	   ft_error_and_exit.c ft_execute_operations.c ft_execute_route_1.c \
	   ft_execute_route_2.c ft_extra.c ft_extra2.c ft_print_list.c \
	   ft_print_result.c ft_push_swap.c ft_push_swap2.c ft_push_swap3.c \
	   ft_solve_decreasing_list.c ft_swap.c ft_validate_input.c main.c

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
