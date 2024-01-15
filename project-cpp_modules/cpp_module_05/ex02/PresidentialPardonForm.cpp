/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:03:55 by fde-fede          #+#    #+#             */
/*   Updated: 2024/01/15 10:14:16 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form( "PresidentialPardonForm", 25, 5 ), _target( target ) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : Form( src ), _target( src._target ) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	(void)rhs;
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if ( executor.getGrade() > this->getGradeToExecute() )
		throw Form::GradeTooLowException();
	else {
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}