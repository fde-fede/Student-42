/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:39:18 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/03 11:41:55 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Default constructor of " << this->type << std::endl;
}

Dog::Dog(const Dog&) : Animal("Dog")
{
	std::cout << "Copy-Constructor of " << this->type << std::endl;
}

Dog::~Dog(void)
{
	std::cout << this->type << " has been destroyed" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "* BARKING! *" << std::endl;
}