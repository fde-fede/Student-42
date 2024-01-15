/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:20:23 by fde-fede          #+#    #+#             */
/*   Updated: 2024/01/15 09:54:40 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
	try {
		Bureaucrat bureaucrat("ash", 11);
		Form form("formName", 10);

		bureaucrat.signForm(form);
		
		std::cout << form << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}