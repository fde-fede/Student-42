# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 12:29:30 by fde-fede          #+#    #+#              #
#    Updated: 2024/04/20 12:30:42 by fde-fede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = iter

CC = c++ -std=c++98
CFLAGS = -I./include -Wall -Wextra -Werror
ifeq ($(shell uname), Linux)
	CC = c++ -g
endif

SRC =  $(shell find . -name "*.cpp")
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@find . -name "*.o" -delete
	@echo "Cleaning"

fclean: clean
	@rm $(NAME)
	@echo "Done"

re: fclean all