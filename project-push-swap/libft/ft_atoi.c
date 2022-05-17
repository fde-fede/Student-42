/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:10:55 by fde-fede          #+#    #+#             */
/*   Updated: 2022/04/25 16:56:26 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_res(int sim, int res)
{
	if (res > 0 && sim < 0)
		return (0);
	if (res < 0 && sim > 0)
		return (-1);
	return (res);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sim;
	int	num;
	int	res;

	i = 0;
	sim = 1;
	num = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sim = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	res = (num * sim);
	return (check_res(sim, res));
}
/*
int	main(void)
{
	char	*a;

	a = "  -\r  -9859hola12";
	printf("%i\n", atoi(a));
	printf("%i\n", ft_atoi(a));
}
*/