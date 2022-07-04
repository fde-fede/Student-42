# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 13:46:23 by fde-fede          #+#    #+#              #
#    Updated: 2022/07/04 13:21:00 by fde-fede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= FDF
CFLAGS	= -Werror -Wall -Wextra
LIBMLX	= ./lib/MLX42
LIBFT	= ./lib/libft

HEADERS	= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	= -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
SRCS	= $(shell find ./ -iname "*.c")
OBJS	= ${SRCS:.c=.o}

all: libft libmlx42 $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

libmlx42:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft