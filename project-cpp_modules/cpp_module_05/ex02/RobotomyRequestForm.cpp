/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:03:55 by fde-fede          #+#    #+#             */
/*   Updated: 2024/01/15 10:21:21 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form( "Robotomy Request Form", 72, 45 ), _target( target ) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : Form( src ), _target( src._target ) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& rhs) {
	(void)rhs;
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if ( executor.getGrade() > this->getGradeToExecute() )
		throw Form::GradeTooLowException();
	else {
		static int	i;
		if ( i % 2 == 0 )
			std::cout << "BZZZZZT! " << _target << " has been robotomized!" << std::endl;
		else
			std::cout << "Robotomy failed! " << _target << " is still alive." << std::endl;
		i++;
	}
}