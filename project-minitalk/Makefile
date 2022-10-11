# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 13:15:51 by fde-fede          #+#    #+#              #
#    Updated: 2022/07/14 17:33:05 by fde-fede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
CFLAGS	= -Werror -Wall -Wextra
LIBFT	= ./libft

HEADERS	= -I $(LIBFT)
LIBS	= $(LIBFT)/libft.a
SRCS	= $(shell find ./ -iname "*.c")
OBJS	= ${SRCS:.c=.o}

all: libft $(SERVER) $(CLIENT)

libft:
	@$(MAKE) -C $(LIBFT)

$(CLIENT): client.o
	@$(CC) client.o $(LIBS) $(HEADERS) -o $@

$(SERVER): server.o
	@$(CC) server.o $(LIBS) $(HEADERS) -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@$(MAKE) -C $(LIBFT) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft