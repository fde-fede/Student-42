/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:12:44 by fde-fede          #+#    #+#             */
/*   Updated: 2022/04/28 18:22:35 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_i(unsigned long long nb, int *i)
{
	if (nb >= 16)
		ft_puthex_i(nb / 16, i);
	ft_putchar_i("0123456789abcdef"[nb % 16], i);
}
