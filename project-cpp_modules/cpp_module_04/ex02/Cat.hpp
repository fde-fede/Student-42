/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:29:18 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/06 10:34:56 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain	*brain;
	public:
		Cat(void);
		Cat(const Cat& other);
		~Cat();

		Cat&	operator=(const Cat& other);
		Animal& operator=(const Animal& other);
		void	makeSound(void) const;
		Brain	*getBrain(void) const;
};