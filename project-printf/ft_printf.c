/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:45:58 by fde-fede          #+#    #+#             */
/*   Updated: 2022/04/28 18:08:45 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void	ft_print_all(const char *str, int *i, va_list args, int j)
{
	if (str[j + 1] == '%')
		ft_putchar_i('%', i);
	else if (str[j + 1] == 'c')
		ft_putchar_i(va_arg(args, int), i);
	else if (str[j + 1] == 's')
		ft_putstr_i(va_arg(args, char *), i);
	else if (str[j + 1] == 'p')
	{
		ft_putstr_i("0x", i);
		ft_puthex_i(va_arg(args, unsigned long long), i);
	}
	else if (str[j + 1] == 'd' || str[j + 1] == 'i')
		ft_putint_i(va_arg(args, int), i);
	else if (str[j + 1] == 'u')
		ft_putui_i(va_arg(args, unsigned int), i);
	else if (str[j + 1] == 'x')
		ft_putnbr_base_i(va_arg(args, unsigned int), "0123456789abcdef", i);
	else if (str[j + 1] == 'X')
		ft_putnbr_base_i(va_arg(args, unsigned int), "0123456789ABCDEF", i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, str);
	while (str[j])
	{
		if (str[j] == '%')
		{
			ft_print_all(str, &i, args, j);
			j++;
		}
		else
			ft_putchar_i(str[j], &i);
		j++;
	}
	return (i);
}
