/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:22:20 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/05 18:54:41 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#define NUMBER_OF_ANIMALS 8

int	main() {
	Animal	*animals[NUMBER_OF_ANIMALS];
	Brain	*brain;

	std::cout << "\nCreatig Animals' array\n" << std::endl;
	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << "Assigning some ideas ti animal[7]" <<std::endl;
	brain = animals[7]->getBrain();
	brain->addIdea("I'm hungry");
	brain->addIdea("That's a strange idea I'm having");
	brain->addIdea("Ball!!!!!");
	brain->addIdea("Squirrel!!!!!");
	std::cout << "First idea of animal[7]: " << brain->getIdea(0) << std::endl;

	std::cout << "\nAssigning animal[7] to animal[5]" << std::endl;
	*(animals[5]) = *(animals[7]);
	std::cout << "First idea of animal[5]: " << animals[5]->getBrain()->getIdea(0) << std::endl;

	std::cout << "\nAdding different ideas to animals[5] and animals[7] (deep copy)" << std::endl;
	animals[5]->getBrain()->addIdea("Last idea of animals[5]");
	std::cout << "Last idea of animal[5]: " << animals[5]->getBrain()->getIdea(4) << std::endl;
	animals[7]->getBrain()->addIdea("Last idea of animals[7]");
	std::cout << "Last idea of animal[7]: " << animals[7]->getBrain()->getIdea(4) << std::endl;
	
	std::cout << "\nDestructing Animals\n" << std::endl;
	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
		delete animals[i];
}