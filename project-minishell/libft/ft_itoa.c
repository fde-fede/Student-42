/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 02:08:34 by fde-fede          #+#    #+#             */
/*   Updated: 2022/04/25 17:39:53 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digit_counter(int n)
{
	int	i;
	int	cpy;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	cpy = n;
	while (cpy > 0)
	{
		cpy = cpy / 10;
		i++;
	}
	return (i);
}

int	exp_counter(int n)
{
	int	exp;
	int	digits;

	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (1000000000);
	digits = digit_counter(n);
	if (n < 0)
		digits--;
	exp = 1;
	while (--digits)
		exp = exp * 10;
	return (exp);
}

char	*ft_itoa(int n)
{
	int				i;
	int				exp;
	long int		num;
	char			*str_num;

	num = (long int)n;
	exp = exp_counter(n);
	i = 0;
	str_num = malloc(digit_counter(n) + 1);
	if (!str_num)
		return (0);
	if (n < 0)
	{
		str_num[i++] = '-';
		num = -num;
	}
	while (exp > 0)
	{
		str_num[i++] = (num / exp) + 48;
		num = num % exp;
		exp = exp / 10;
	}
	str_num[i] = '\0';
	return (str_num);
}
/*
int main(void)
{
	printf("%s\n", ft_itoa(579));
}
*/