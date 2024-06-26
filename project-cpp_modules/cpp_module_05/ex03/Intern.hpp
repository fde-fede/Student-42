/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:54:35 by fde-fede          #+#    #+#             */
/*   Updated: 2024/04/10 16:18:22 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
	public:
		/* Constructors & Destructors */
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);

		/* Basic Operators */
		Intern const	&operator=(Intern const &copy);

		/* Main Member Functions */
		Form	*makeForm(std::string const &type, std::string const &target);
};
