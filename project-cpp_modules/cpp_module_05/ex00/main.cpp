/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:20:23 by fde-fede          #+#    #+#             */
/*   Updated: 2024/01/15 09:24:13 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
	try {
		Bureaucrat bureaucrat("ash", 20);
		
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}