/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:37:08 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/22 17:17:53 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;

	if (ft_strlen(s) < start)
	{
		str = (char *)ft_calloc(sizeof(char), 1);
		if (!str)
			return (NULL);
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (ft_min(ft_strlen(s), len) + 1));
	if (!str)
		return (NULL);
	index = 0;
	while (index != ft_min(ft_strlen(s), len))
	{
		str[index] = s[start];
		start++;
		index++;
	}
	str[index] = '\0';
	return (str);
}
