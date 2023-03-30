# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 21:12:30 by fde-fede          #+#    #+#              #
#    Updated: 2023/01/10 12:24:12 by fde-fede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PhoneBook

CC			= c++
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

OBJDIR = .objFiles

FILES		= main Contact Phonebook

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= Contact.class.hpp Phonebook.class.hpp

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