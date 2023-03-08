/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:52:49 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/22 17:17:53 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(const int n)
{
	size_t	size;
	long	temp;

	temp = n;
	size = 0;
	if (n < 0)
		temp *= -1;
	while (temp > 9)
	{
		temp = temp / 10;
		size++;
	}
	size++;
	return (size);
}

size_t	ft_uintlen(const unsigned int n)
{
	size_t	size;
	long	temp;

	temp = n;
	size = 0;
	while (temp > 9)
	{
		temp = temp / 10;
		size++;
	}
	size++;
	return (size);
}
