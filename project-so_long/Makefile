# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 18:53:01 by fde-fede          #+#    #+#              #
#    Updated: 2023/04/04 18:44:42 by fde-fede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	Game
CFLAGS		:=	-Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX		:=	/Users/felixjr/Desktop/42/project-so_long/lib/MLX42
#LIBMLX		:=	/Users/fde-fede/Student-42/project-so_long/lib/MLX42

HEADERS		:=	-I ./includes -I $(LIBMLX)/include
LIBS		:=	$(LIBMLX)/libmlx42.a -I include -lglfw -L "/sgoinfre/goinfre/Perso/fde-fede/homebrew/opt/glfw/lib" -ldl -pthread
SRCS		:=	$(shell find ./srcs -iname "*.c")
OBJS		:=	${SRCS:.c=.o}

all:	$(NAME)

#libmlx:
#		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
		@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"
		
$(NAME): $(OBJS)
		@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx