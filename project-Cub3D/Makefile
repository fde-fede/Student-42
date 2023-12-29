# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 11:38:25 by joslopez          #+#    #+#              #
#    Updated: 2023/08/24 18:10:28 by joslopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

GCC_FLAG = -Wall -Wextra -Werror

SRCS = ./srcs/mandatory/map.c \
	   ./srcs/mandatory/cub3d.c \
	   ./srcs/mandatory/utils.c \
	   ./srcs/mandatory/utils2.c \
	   ./srcs/mandatory/initializer.c \
	   ./srcs/mandatory/parser.c \
	   ./srcs/mandatory/parser_orientation.c \
	   ./srcs/mandatory/events.c \
	   ./srcs/mandatory/movement.c \
	   ./srcs/mandatory/display.c \
	   ./srcs/mandatory/free.c \
	   ./srcs/mandatory/controls.c \
	   ./srcs/mandatory/floor_ceil.c \
	   ./srcs/mandatory/raycasting.c \
	   ./srcs/mandatory/rendering.c \
	   ./srcs/mandatory/textures.c \
	   ./srcs/get_next_line/get_next_line.c \
	   ./srcs/get_next_line/get_next_line_utils.c \


OBJS = $(SRCS:.c=.o)

all: libft minilibx $(NAME)

libft:
	make -C libft/

minilibx:
	make -C srcs/minilibx/


$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME): $(OBJS)
	$(CC) -o $@ $^ -Lsrcs/minilibx/ -lmlx -framework OPENGL -framework Appkit -Llibft -lft

clean:
	rm -f $(OBJS)
	make -Clibft/ clean
	make -C srcs/minilibx/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C srcs/minilibx/ clean

re: fclean all

.PHONY: libft minilibx