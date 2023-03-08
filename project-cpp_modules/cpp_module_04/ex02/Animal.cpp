/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:28:32 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/06 10:34:12 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::~Animal(void)
{
	std::cout << "Destructor of Animal" << std::endl;
}

const std::string&	Animal::getType(void) const
{
	return (this->type);
}

void		Animal::setType(const std::string& type)
{
	this->type = type;
}