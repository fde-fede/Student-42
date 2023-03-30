/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:38:03 by fde-fede           #+#    #+#             */
/*   Updated: 2023/02/02 17:59:26 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	FragTrap	temp("Daniel");
	FragTrap	Daniel("No name");

	/* Assignment check */
	Daniel = temp;

	/* Information */
	Daniel.setAttackDamage(2);
	std::cout << "\n--------- FragTrap Daniel ----------" << std::endl;
	std::cout << "Hitpoints: " << Daniel.getHitPoints() << " ";
	std::cout << "Energy: " << Daniel.getEnergyPoints() << " ";
	std::cout << "Attack Damage: " << Daniel.getAttackDamage() << " ";
	std::cout << "Status: Active" << std::endl;

	/* Test */
	std::cout << "\nStart attacking...\n" << std::endl;

	Daniel.attack("Sharks");
	Daniel.attack("Pirates");
	Daniel.takeDamage(3);
	Daniel.takeDamage(14);
	Daniel.beRepaired(10);
	Daniel.attack("Dragon");
	Daniel.attack("Spirits");
	Daniel.attack("Kings");
	Daniel.highFivesGuys();

	std::cout << "\nFights are over...\n" << std::endl;
}