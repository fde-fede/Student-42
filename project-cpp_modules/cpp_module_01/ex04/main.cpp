/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:18:39 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 18:20:15 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main ( int ac, char **av )
{
	if (ac != 4) {
		std::cerr << "Usage: ./Sed <filename> <to_find> <replace>." << std::endl;
		return EXIT_FAILURE;
	} else {
		Sed		Sed(av[1]);
		Sed.replace(av[2], av[3]);
	}
	return EXIT_SUCCESS;
}