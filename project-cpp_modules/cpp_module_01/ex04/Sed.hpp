/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:10:40 by fde-fede          #+#    #+#             */
/*   Updated: 2023/01/17 18:12:20 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed {
	private:
		std::string _inFile;
		std::string _outFile;
	
	public:
		Sed( std::string filename );
		~Sed();

		void	replace( std::string s1, std::string s2 );
};

#endif