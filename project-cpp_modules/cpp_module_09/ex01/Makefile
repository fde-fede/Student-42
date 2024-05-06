# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 11:11:35 by fde-fede          #+#    #+#              #
#    Updated: 2024/05/06 10:36:42 by fde-fede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CC = c++ -std=c++98
CFLAGS = -I./include -Wall -Wextra -Werror
ifeq ($(shell uname), Linux)
	CC = c++ -g
endif

SRC =  $(shell find . -name "*.cpp")
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@find . -name "*.o" -delete
	@echo "Cleaning"

fclean: clean
	@rm $(NAME)
	@echo "Done"

re: fclean all