/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:28:32 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/18 14:32:45 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Default constructor of Animal" << std::endl;
}

Animal::Animal(const std::string& type)
{
	std::cout << "Type constructor of Animal" << std::endl;
	this->type = type;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copy-Constructor of Animal" << std::endl;
	*this = other;
}

Animal::~Animal(void)
{
	std::cout << "Destructor of Animal" << std::endl;
}

Animal&		Animal::operator=(const Animal& other)
{
	this->type = other.getType();

	return (*this);
}

const std::string&	Animal::getType(void) const
{
	return (this->type);
}

void		Animal::setType(const std::string& type)
{
	this->type = type;
}

void	Animal::makeSound(void) const
{
	std::cout << "* Animal Sound!!! *" << std::endl;
}