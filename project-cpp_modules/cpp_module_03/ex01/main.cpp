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

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	temp("Daniel");
	ScavTrap	Daniel("No name");

	/* Assignment check */
	temp.setAttackDamage(55);
	Daniel = temp;

	/* Information */
	Daniel.setAttackDamage(2);
	std::cout << "\n--------- ScavTrap Daniel ----------" << std::endl;
	std::cout << "Hitpoints: " << Daniel.getHitPoints() << " ";
	std::cout << "Energy: " << Daniel.getEnergyPoints() << " ";
	std::cout << "Attack Damage: " << Daniel.getAttackDamage() << " ";
	std::cout << "Status: Active" << std::endl;

	/* Test */
	std::cout << "\nStart attacking...\n" << std::endl;

	Daniel.attack("Sharks");
	Daniel.attack("Pirates");
	Daniel.takeDamage(3);
	Daniel.takeDamage(4);
	Daniel.beRepaired(10);
	Daniel.attack("Dragon");
	Daniel.attack("Spirits");
	Daniel.attack("Lions");
	Daniel.attack("Kings");

	std::cout << "\nFights are over. Guarding time...\n" << std::endl;
	Daniel.guardGate();
	std::cout << "\nGuarded too much... Enough!\n" << std::endl;
}