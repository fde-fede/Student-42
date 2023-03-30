/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:46:13 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/21 17:48:21 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Default constructor of " << this->type << std::endl;
}

Cat::Cat(const Cat&) : Animal("Cat")
{
	std::cout << "Copy-Constructor of " << this->type << std::endl;
}

Cat::~Cat(void)
{
	std::cout << this->type << " has been destroyed" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "* MEOW! *" << std::endl;
}