/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:42:19 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/18 13:33:38 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "<DiamondTrap default constructor has been called!" << std::endl;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), name(name)
{
	std::cout << "<DiamondTrap " << this->name << "> Status: Created" << std::endl;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
	: ClapTrap(other.name + "_clap_trap"), ScavTrap(other.name + "_clap_trap"), FragTrap(other.name + "_clap_trap")
{
	std::cout << "<DiamondTrap copy-constructor has been called!> Status: Cloned" << std::endl;
	this->name = other.name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "<DiamondTrap " << this->name << "> Status: Dead" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "<DiamondTrap " << this->name << "> DiamondTrap->name: " << this->name << std::endl;
	std::cout << "<DiamondTrap " << this->name << "> ClapTrap->name: " << ClapTrap::name << std::endl;
}