/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:45:07 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/04 15:38:09 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "Default Constructor of WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type)
{
	std::cout << "Type constructor of WrongAnimal" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "Copy-Constructor of WrongAnimal" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor of WrongAnimal" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	this->type = other.getType();
	return (*this);
}

const std::string&	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::setType(const std::string& type)
{
	this->type = type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "* WrongAnimal Sound!! *" << std::endl;
}