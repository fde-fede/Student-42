/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:52:55 by fde-fede          #+#    #+#             */
/*   Updated: 2024/02/26 13:40:59 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert <number>" << std::endl;
		return EXIT_FAILURE;
	}

	ScalarConverter c;

	try
	{
		c.setStr(av[1]);
		c.convert();

		std::cout << c;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return EXIT_SUCCESS;
}