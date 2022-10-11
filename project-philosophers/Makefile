# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 19:42:41 by fde-fede          #+#    #+#              #
#    Updated: 2022/10/10 20:15:43 by fde-fede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = ./includes/

CC = gcc

CFLAGS = -Werror -Wall -Wextra -g -I $(HEADER) -pthread

SRCS =	srcs/philosophers.c \
			srcs/activity.c \
			srcs/init_and_parse.c \
			srcs/utils_philo.c \
			srcs/utils_lib.c \
			srcs/threads.c

OBJS = $(SRCS:.c=.o)

all :	$(NAME)

$(NAME) : $(OBJS) $(HEADER)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all