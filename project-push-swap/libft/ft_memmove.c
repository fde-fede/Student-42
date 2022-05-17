/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:47:06 by fde-fede          #+#    #+#             */
/*   Updated: 2022/04/25 14:07:32 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned const char	*s;
	unsigned char		*d;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	d = (unsigned char *)dst;
	s = (unsigned const char *)src;
	if (dst == src || !len)
		return (dst);
	while (len--)
		d[len] = s[len];
	return (dst);
}
