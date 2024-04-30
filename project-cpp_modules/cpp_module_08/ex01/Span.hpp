/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:53:24 by fde-fede          #+#    #+#             */
/*   Updated: 2024/04/30 08:56:14 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>


class Span{
public:
	Span(unsigned int);
	Span(Span const &);
	Span &operator=(Span const &);
	~Span();

	void	addNumber(int);
	void	addNumber(std::vector<int>::iterator, std::vector<int>::iterator);
	class maxsizereached: public std::exception{
	public: const char * what() const throw(){
		return "Vector is full"; }
	};

	int	shortestSpan();
	int	longestSpan();
	class notfound: public std::exception{
	public: const char * what() const throw(){
		return "Element is not found"; }
	};

	int	maxnumber();
	int	minnumber();

private:
	std::vector<int>	_arr;
	long unsigned int	_size;
};