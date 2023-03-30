/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:34:39 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 18:36:12 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void ) {
	std::string	input;
	Harl		harl;

	do
	{
		std::cout << "Enter a level: ";
		std::cin >> input;
		harl.complain(input);
	} while (input.compare("exit"));

	return EXIT_SUCCESS;
}