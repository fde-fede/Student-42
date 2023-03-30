/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:23:00 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/05 18:42:51 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal {
	protected:
			std::string	type;
			Animal(const std::string& type);
	public:
			Animal(void);
			Animal(const Animal& other);
			virtual ~Animal(void);

			virtual Animal&				operator=(const Animal& other);
			const std::string&	getType(void) const;
			void				setType(const std::string& type);
			virtual void		makeSound(void) const;
			virtual Brain		*getBrain(void) const = 0;
};