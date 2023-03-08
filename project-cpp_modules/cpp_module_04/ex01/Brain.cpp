/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:15:29 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/05 18:41:37 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default constructor of Brain" << std::endl;
	size = 0;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Copy-Constructor of Brain" << std::endl;
	*this = other;
}

Brain::~Brain(void)
{
	std::cout << "Destructor of Brain" << std::endl;
}

Brain&		Brain::operator=(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	this->size = other.size;
	return (*this);
}

const std::string&	Brain::getIdea(unsigned int index) const
{
	return (this->ideas[index]);
}

void		Brain::addIdea(std::string idea)
{
	if (size == 100)
		return;
	this->ideas[size++] = idea;
}