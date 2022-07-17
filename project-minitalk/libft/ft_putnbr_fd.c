/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:36:54 by fde-fede          #+#    #+#             */
/*   Updated: 2022/04/25 18:19:18 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	tmp;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp = (unsigned int)(n * -1);
	}
	else
		tmp = (unsigned int)n;
	if (tmp >= 10)
		ft_putnbr_fd(tmp / 10, fd);
	ft_putchar_fd((char)(tmp % 10 + 48), fd);
}
