/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:53:17 by fde-fede          #+#    #+#             */
/*   Updated: 2024/04/30 08:56:12 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int n) : _size(n) {
}

Span::Span(Span const &s) {
	_arr = s._arr;
	_size = s._size;
}

Span &Span::operator=(Span const &s){
	_arr = s._arr;
	_size = s._size;
	return *this;
}

Span::~Span()
{ }

void	Span::addNumber(int n){
	if (_arr.size() < _size)
		_arr.push_back(n);
	else
		throw maxsizereached();
}

void	Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator finish)
{
	std::vector<int> tmp(start, finish);

	if (tmp.size() > (_size - _arr.size()))
		throw maxsizereached();
	std::copy(tmp.begin(), tmp.end(), std::back_inserter(_arr));
}

int	Span::longestSpan(){
	return (maxnumber() - minnumber());
}

int	Span::shortestSpan(){
	int ret = longestSpan();
	std::vector<int>::iterator	i = _arr.begin();
	for (; i < _arr.end(); i++)
	{
		std::vector<int>::iterator	j = _arr.begin();
		for (; j < _arr.end(); j++)
		{
			if (i == j)
				continue ;
			if (*i > *j && *i - *j < ret)
				ret = *i - *j;
			else if (*i < *j && *j - *i < ret)
				ret = *j - *i;
		}
	}
	return ret;
}

int	Span::maxnumber(){
	std::vector<int>::iterator i = _arr.begin();
	int	ret = *i;
	for (; i < _arr.end(); i++){
		if (ret < *i)
			ret = *i;
	}
	return ret;
}

int	Span::minnumber(){
	std::vector<int>::iterator i = _arr.begin();
	int	ret = *i;
	for (; i < _arr.end(); i++){
		if (ret > *i)
			ret = *i;
	}
	return ret;
}