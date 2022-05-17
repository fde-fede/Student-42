/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:32:49 by fde-fede          #+#    #+#             */
/*   Updated: 2022/04/25 18:16:04 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s != 0)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}