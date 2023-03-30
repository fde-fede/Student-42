/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:43:51 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/06 14:57:30 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : size(0)
{
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	*this = other;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < size; i++)
		delete this->materias[i];
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	this->size = other.size;
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
		this->materias[i] = other.materias[i];
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *m)
{
	if (this->size >= 4)
		std::cout << "Can't learn any more materias" << std::endl;
	else
	{
		this->materias[size] = m;
		size++;
	}
}

AMateria	*MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4 && this->materias[i]; i++)
	{
		if (type == this->materias[i]->getType())
			return this->materias[i]->clone();
	}
	return NULL;
}

void		MateriaSource::printMaterias(void) const
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i])
			std::cout << i << ": " << this->materias[i]->getType() << std::endl;
		else
			std::cout << i << ": Empty" << std::endl;
	}
}