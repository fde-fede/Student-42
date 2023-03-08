/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:53:28 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/18 13:27:21 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "<ScavTrap " << this->name << "> Status: Created" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "<ScavTrap copy-constructor has been called!> Status: Cloned" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "<ScavTrap " << this->name << "> Status: Dead" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints < 5)
	{
		std::cout << "<ScavTrap " << this->name << " does not have nough energy to attack> ";
		std::cout << "Energy: " << this->energyPoints << " Status: Exhausted" << std::endl; 
	}
	else
	{
		this->energyPoints -= 5;
		std::cout << "<ScavTrap " << this->name << " attack " << target;
		std::cout << ", causing " << this->attackDamage << " points of damage!> ";
		std::cout << "Energy: " << this->energyPoints << " Status: Attacked" << std::endl;
	}
}

void	ScavTrap::guardGate(void) const
{
	std::cout << "<ScavTrap " << this->name << " is guarding the gates> ";
	std::cout << "Status: Guarding" << std::endl;
}