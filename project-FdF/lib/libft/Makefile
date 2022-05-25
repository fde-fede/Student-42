# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 13:49:21 by fde-fede          #+#    #+#              #
#    Updated: 2022/05/22 19:29:18 by fde-fede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCRS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c\
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
get_next_line.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = ${SCRS:.c=.o}

NAME = libft.a

.c.o: ${CC} -c $< -o ${<:.c=.o}

CC = gcc

CFLAGS = -Wextra -Wall -Werror

all: ${NAME}


$(NAME):
	${MAKE} -C printf
	cp printf/libftprintf.a ./libft.a
	${CC} -c ${CFLAGS} ${SCRS}
	ar rs ${NAME} ${OBJS}

clean:
		rm -f ${OBJS}
		${MAKE} -C printf clean

fclean: clean
		rm -f ${NAME}
		${MAKE} -C printf fclean

re: fclean all

.PHONY: all, clean, fclean, re