# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdruta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/02 16:35:04 by vdruta            #+#    #+#              #
#    Updated: 2016/02/02 18:08:34 by vdruta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = ft_generate_initial_coordinates.c ft_move.c ft_validate_char_map.c \
	   ft_color.c ft_get_cmap.c ft_print_matrix.c ft_zoom_color.c draw_line.c \
		ft_control_height.c ft_get_int_map.c ft_project_isometric_matrix.c \
		key_hook.c expose_hook.c ft_draw_line_betwen_points.c \
		ft_get_zmin_zmax.c ft_show_usage.c ft_error_and_exit.c ft_init_env.c \
		ft_transform_to_map_center.c main.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	gcc -Wall -Werror -Wextra -I libft/includes/ -c $(SRCS)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f libft/libft.a

re: fclean all
