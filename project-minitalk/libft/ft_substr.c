/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:28:27 by fde-fede          #+#    #+#             */
/*   Updated: 2022/04/25 15:29:07 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dest;

	dest = (char *)malloc(len + 1);
	if (!s || !dest)
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		dest[j++] = s[i++];
	dest[j] = '\0';
	return (dest);
}
