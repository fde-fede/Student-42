/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:56:16 by fde-fede          #+#    #+#             */
/*   Updated: 2024/01/15 13:02:05 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern( const Intern& src ) {
	*this = src;
}

Intern::~Intern() {}

Intern& Intern::operator=( const Intern& rhs ) {
	( void ) rhs;
	return (*this);
}

Form*	Intern::makeForm( std::string name, std::string target ) {

	std::string formNames[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	Form*	forms[] = {
		new RobotomyRequestForm( target ),
		new PresidentialPardonForm( target ),
		new ShrubberyCreationForm( target )
	};

	for ( int i(0); i < 3; i++ ) {
		if ( name == formNames[i] ) {
			std::cout << "Intern creates " << name << std::endl;
			return forms[i];
		}
	}
	std::cout << "Intern cannot create " << name << " form" << std::endl;
	return nullptr;
}