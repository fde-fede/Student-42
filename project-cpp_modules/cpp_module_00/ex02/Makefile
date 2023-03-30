# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 17:05:49 by fde-fede          #+#    #+#              #
#    Updated: 2023/03/28 17:06:24 by fde-fede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Account

CC			= c++
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

OBJDIR = .objFiles

FILES		= Account tests

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= Account.hpp

ifeq ($(DEBUG), 1)
	OPTS = -g
endif

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
		@$(CC) $(OBJ) $(OPTS) -o $(NAME)
		@printf "$(_SUCCESS) - Executable ready.\n$(RESET)"
		
$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@printf "  - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "  - Executable removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re bonus norm