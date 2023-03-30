/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:23:00 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/18 14:28:30 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal {
	protected:
			std::string	type;
			Animal(const std::string& type);
	public:
			Animal(void);
			Animal(const Animal& other);
			virtual ~Animal(void);

			Animal&				operator=(const Animal& other);
			const std::string&	getType(void) const;
			void				setType(const std::string& type);
			virtual void		makeSound(void) const;
};