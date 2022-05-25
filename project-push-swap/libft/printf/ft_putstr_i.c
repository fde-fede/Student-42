/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:16:44 by fde-fede          #+#    #+#             */
/*   Updated: 2022/04/28 18:18:06 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putstr_i(char *str, int *i2)
{
	int	i;

	if (!str)
	{
		ft_putstr_i("(null)", i2);
		return ;
	}
	i = 0;
	while (str[i])
	{
		write(1, &(str[i]), 1);
		i++;
	}
	*i2 += i;
}
