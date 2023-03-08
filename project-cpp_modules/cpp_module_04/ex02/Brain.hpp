/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:11:51 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/04 16:15:07 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Brain {
	private:
			std::string		ideas[100];
			unsigned int	size;
	public:
			Brain(void);
			Brain(const Brain& other);
			~Brain(void);

			Brain&				operator=(const Brain& other);
			void				addIdea(std::string idea);
			const std::string&	getIdea(unsigned int index) const;
};