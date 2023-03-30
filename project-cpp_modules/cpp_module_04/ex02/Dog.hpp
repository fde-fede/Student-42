/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:42:54 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/06 10:35:32 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
			Brain	*brain;
	public:
			Dog(void);
			Dog(const Dog& other);
			~Dog();

			Dog&	operator=(const Dog& other);
			Animal&	operator=(const Animal& other);
			void	makeSound(void) const;
			Brain	*getBrain(void) const;
};