/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:38:21 by fde-fede           #+#    #+#             */
/*   Updated: 2023/02/02 17:50:09 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* Constructors and Destructor */

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor has been called!" << std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "<ClapTrap copy-constructor has been called!> Status: Cloned" << std::endl;
	*this = other;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "<ClapTrap " << name << "> " << "Status: Created" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "<ClapTrap " << this->name << "> " << "Status: Dead" << std::endl;
}

/* Assignation operator overload */

ClapTrap&		ClapTrap::operator=(const ClapTrap& other)
{
	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAttackDamage(other.getAttackDamage());

	return (*this);
}

/* Getters and Setters */

const std::string&	ClapTrap::getName(void) const
{
	return (this->name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->attackDamage);
}

void	ClapTrap::setName(const std::string& name)
{
	this->name = name;
}

void	ClapTrap::setHitPoints(unsigned int hitPoints)
{
	this->hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(unsigned int damage)
{
	this->attackDamage = damage;
}

/* Action functions */

void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints < 2)
	{
		std::cout << "<ClapTrap " << this->name << " does not have enough energy to attack> ";
		std::cout << "Energy: " << this->energyPoints << " Status: Exhausted" << std::endl;
	}
	else
	{
		this->energyPoints -= 2;
		std::cout << "<ClapTrap " << this->name << " attack " << target;
		std::cout << ", causing " << this->attackDamage << " points of damage!> ";
		std::cout << "Energy: " << this->energyPoints << " Status: Attacked" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->hitPoints)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
	std::cout << "<ClapTrap " << this->name << " got " << amount << " points of damage!>";
	std::cout << " Hitpoints: " << this->hitPoints << " Status: Damaged" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->hitPoints += amount;
	std::cout << "<ClapTrap " << this->name << " got repaired by " << amount << " points!>";
	std::cout << " Hitpoints: " << this->hitPoints << " Status: Repaired" << std::endl;
}