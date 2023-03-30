/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:50:28 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/06 14:57:38 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource {
	private:
			AMateria	*materias[4];
			int			size;
	public:
			MateriaSource(void);
			MateriaSource(const MateriaSource& other);
			~MateriaSource(void);

			MateriaSource		&operator=(const MateriaSource& other);
			
			virtual void		learnMateria(AMateria *m);
			virtual AMateria	*createMateria(const std::string& type);
			void				printMaterias(void) const;
};