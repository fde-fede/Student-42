/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:08:56 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/13 10:44:25 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			size_src;

	i = 0;
	if (src == NULL)
		return (0);
	size_src = ft_strlen(src);
	if ((int)size < 0)
		size = size_src + 1;
	if (size >= 2 && size_src != 0)
	{
		while (i < size - 1)
		{
			if (i < size_src)
				dst[i] = src[i];
			else if (i == size_src)
				dst[i] = '\0';
			i++;
		}
	}
	if (size != 0)
		dst[i] = '\0';
	return (size_src);
}
