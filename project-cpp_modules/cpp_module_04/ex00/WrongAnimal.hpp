/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:45:18 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/03 11:47:45 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
	protected:
			std::string		type;
			WrongAnimal(const std::string& type);
	public:
			WrongAnimal(void);
			WrongAnimal(const WrongAnimal& other);
			virtual ~WrongAnimal(void);

			WrongAnimal&	operator=(const WrongAnimal& other);
			const std::string&	getType(void) const;
			void				setType(const std::string& type);
			void	makeSound(void) const;
};