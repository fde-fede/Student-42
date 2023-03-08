/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:48:01 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/06 11:54:20 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
			Cure(void);
			Cure(const Cure& other);
			~Cure(void);

			Cure&	operator=(const Cure& other);
			AMateria*	clone() const;
			void		use(ICharacter& target);
};