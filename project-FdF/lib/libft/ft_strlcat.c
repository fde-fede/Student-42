/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:44:22 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/22 17:17:53 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	src_length;
	size_t	dst_length;

	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	while (*dst)
		dst++;
	index = 0;
	if (size <= dst_length)
		return (size + src_length);
	while (src[index] && index < size - dst_length - 1)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (src_length + dst_length);
}
