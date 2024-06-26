/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:59:27 by fde-fede          #+#    #+#             */
/*   Updated: 2024/05/06 14:51:11 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file" << std::endl;
		return (EXIT_FAILURE);
	}

	BitcoinExchange exchange;

	exchange.run(av[1]);

	return (EXIT_SUCCESS);
}