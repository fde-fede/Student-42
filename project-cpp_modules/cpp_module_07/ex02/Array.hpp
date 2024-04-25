/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:38:09 by fde-fede          #+#    #+#             */
/*   Updated: 2024/04/25 08:32:35 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template < typename T >
class Array {

private:
    T*              _arr;
    unsigned int    _size;

public:
    Array( void ) : _arr( new T() ), _size( 0 ) {};
    Array( unsigned int n ) : _arr( new T[n] ), _size( n ) {};
    Array( const Array& rhs ) : _arr( new T[rhs.size()] ), _size( rhs.size() ) {
        for ( unsigned int i( 0 ); i < _size; i++ )
            _arr[i] = rhs._arr[i];
    };

    Array& operator=( const Array& rhs ) {
        if ( this != &rhs ) {
            delete [] _arr;
            _arr = new T[rhs.size()];
            _size = rhs._size;
            for ( unsigned int i( 0 ); i < _size; i++ )
                _arr[i] = rhs._arr[i];
        }
        return *this;
    }

    T& operator[]( unsigned int i ) const {
        if ( i >= _size )
            throw OutOfBoundsException();
        return _arr[i];
    }

    unsigned int  size( void ) const { return _size; }

    ~Array( void ) { delete [] _arr; }

    class OutOfBoundsException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Index is out of bounds";}
    };
};

template < typename T >
std::ostream& operator<<( std::ostream& out, const Array<T>& arr ) {
    for ( unsigned int i( 0 ); i < arr.size(); i++ )
        out << arr[i] << " ";
    return out;
}