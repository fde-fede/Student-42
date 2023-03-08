/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:39:18 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/06 10:42:55 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Default constructor of " << this->type << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::Dog(const Dog& other)
{
	std::cout << "Copy-Constructor of " << this->type << std::endl;
	*this = other;
}

Dog::~Dog(void)
{
	std::cout << this->type << " has been destroyed" << std::endl;
	delete this->brain;
}

Dog&		Dog::operator=(const Dog& other)
{
	this->type = other.type;
	*(this->brain) = *(other.brain);

	return (*this);
}

Animal&		Dog::operator=(const Animal& other)
{
	const Dog	*pOther;

	pOther = dynamic_cast<const Dog*>(&other);
	if (pOther)
	{
		this->type = pOther->type;
		*this->brain = *pOther->brain;
	}

	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "* BARKING! *" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return (this->brain);
}