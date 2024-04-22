/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:55:10 by fde-fede          #+#    #+#             */
/*   Updated: 2024/02/26 13:50:05 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>
#include <fstream>
#include <limits>

enum e_type {
	NONE,
	INT,
	FLOAT,
	CHAR,
	DOUBLE,
	LITERALS
};

class ScalarConverter {
	private:
		char	_c;
		int		_n;
		float	_f;
		double	_d;

		bool	_impossible;

		std::string	_str;
		e_type		_type;

	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter(void);

		ScalarConverter& operator=(const ScalarConverter& rhs);
		
		char getC(void) const;
		void setC(char c);
		int	getI(void) const;
		void setI(int n);
		float getF(void) const;
		void setF(float F);
		double getD(void) const;
		void setD(double d);
		void    convert( void );

    	void    setStr( std::string str );
    	std::string    getStr( void ) const;
	
    	e_type  getType( void ) const;
    	void    setType( void );
	
    	bool    isChar( void ) const;
    	bool    isInt( void ) const;
    	bool    isFloat( void ) const;
    	bool    isDouble( void ) const;
	
    	bool    isImpossible( void );
	
    	void    printChar( void ) const ;
    	void    printInt( void ) const ;
    	void    printFloat( void ) const ;
    	void    printDouble( void ) const ;
	
    	bool    isLiterals( void ) const;

		class ConverterException : public std::exception {
			virtual const char* what() const throw() { return "Unknown type";}
		};
};

std::ostream& operator <<(std::ostream& out, const ScalarConverter& rhs);

#endif