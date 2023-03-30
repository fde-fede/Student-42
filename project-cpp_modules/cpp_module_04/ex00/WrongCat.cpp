/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:45:41 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/04 15:53:09 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "Default constructor of " << this->type << std::endl;
}

WrongCat::WrongCat(const WrongCat&) : WrongAnimal("WrongCat")
{
	std::cout << "Copy-Constructor of " << this->type << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << this->type << " has been destroyed" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "* WrongCat MEOW *" << std::endl;
}