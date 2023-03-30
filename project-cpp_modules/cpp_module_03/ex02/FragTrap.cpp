/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:33:12 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/17 16:17:53 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor has been called!" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "<FragTrap " << this->name << "> Status: Created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "<FragTrap copy-constructor has been called!> Status: Cloned" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "<FragTrap " << this->name << "> Status: Dead" << std::endl;
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "<FragTrap " << this->name << "> High Five Guys! Status: Friendly" << std::endl;
}