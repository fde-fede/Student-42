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

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	Jack("Jack");

	/* Information */
	Jack.setAttackDamage(2);
	std::cout << "\n--------- ClapTrap Jack ----------" << std::endl;
	std::cout << "Hitpoints: " << Jack.getHitPoints() << " ";
	std::cout << "Energy: " << Jack.getEnergyPoints() << " ";
	std::cout << "Attack Damage: ""
}