# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 16:48:49 by fde-fede          #+#    #+#              #
#    Updated: 2022/06/09 16:49:12 by fde-fede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= SO_LONG
CFLAGS	= -Werror -Wall -Wextra
LIBMLX	= ./lib/MLX42
LIBFT	= ./lib/libft

HEADERS	= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	= -lglfw $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
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