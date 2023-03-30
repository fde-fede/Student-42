/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:21:33 by fde-fede           #+#    #+#             */
/*   Updated: 2023/01/25 13:10:56 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const float val)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = (int)roundf(val * (1 << Fixed::fractBits));
}

Fixed::Fixed(const int val)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = (val << Fixed::fractBits);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed&  Fixed::operator=(const Fixed& other)
{
    std::cout << "Assignation operator called" << std::endl;
    this->setRawBits(other.getRawBits());
    return (*this);
}

std::ostream&   operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}

int     Fixed::getRawBits() const
{
    return (this->value);
}

void    Fixed::setRawBits(const int raw)
{
    this->value = raw;
}

int  Fixed::toInt() const
{
    return (this->value >> Fixed::fractBits);
}

float   Fixed::toFloat() const
{
    return ((float)this->value / (float)(1 << Fixed::fractBits));
}