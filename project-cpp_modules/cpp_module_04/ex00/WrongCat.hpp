/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:46:06 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/04 15:47:19 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
		public:
			WrongCat(void);
			WrongCat(const WrongCat&);
			~WrongCat();

			using	WrongAnimal::operator=;
			void	makeSound(void) const;
};