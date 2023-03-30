/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:07:47 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 12:10:37 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void ) {
	std::string name;

	std::cout << "Creating zombie on stack." << std::endl;
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;

	Zombie zombi1(name);
	
	std::cout << "Creating zombie on the heap." << std::endl;
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;

	Zombie *zombi2 = newZombie(name);
	zombi2->announce();
	delete zombi2;

	std::cout << "Calling randomChump()." << std::endl;
	randomChump("randi");
	return 0;
}