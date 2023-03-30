/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:12:20 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/22 17:17:53 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	index;

	if (!dst && !src)
		return (0);
	if (dst <= src)
	{
		index = 0;
		while (index != n)
		{
			((char *)dst)[index] = ((char *)src)[index];
			index++;
		}
	}
	else
	{
		index = n;
		while (index != 0)
		{
			index--;
			((char *)dst)[index] = ((char *)src)[index];
		}
	}
	return (dst);
}
