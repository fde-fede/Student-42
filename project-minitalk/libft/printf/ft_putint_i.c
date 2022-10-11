/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:14:23 by fde-fede          #+#    #+#             */
/*   Updated: 2022/04/28 18:16:30 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putint_i(int nb, int *i)
{
	long long	nbr;

	nbr = (long long)nb;
	if (nbr < 0)
	{
		ft_putchar_i('-', i);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putint_i(nbr / 10, i);
		nbr %= 10;
	}
	ft_putchar_i(nbr + '0', i);
}
