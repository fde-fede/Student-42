# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 09:25:42 by fde-fede          #+#    #+#              #
#    Updated: 2024/04/11 14:51:51 by fde-fede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Intern

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

OBJDIR = .objFiles

FILES	= main Bureaucrat Form PresidentialPardonForm RobotomyRequestForm ShrubberyCreationForm Intern

SRC		= $(FILES:=.cpp)
OBJ		= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER	= Bureaucrat.hpp Form.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp

#Colors:
GREEN	=	\e[92;5;118m
YELLOW	=	\e[93;5;226m
GRAY	=	\e[33;2;37m
RESET	=	\e[0m
CURSIVE	=	\e[33;3m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ) ShrubberyCreationForm_shrubbery Fred_shrubbery
	@printf "$(YELLOW)	- Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)	- Executable removed.$(RESET)\n"

re: fclean all