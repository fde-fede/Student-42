/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:01:24 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 19:04:07 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( int ac, char **av ) {
	if (ac != 2) {
		return (std::cout << "Usage: ./harlFilter \"level\"\n", EXIT_FAILURE);
	}
	std::string	input = av[1];
	Harl		harl;

	harl.complain(input);

	return EXIT_SUCCESS;
}