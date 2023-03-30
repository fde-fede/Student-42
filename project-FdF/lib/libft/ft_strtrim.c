/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:14:59 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/22 17:17:53 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		index;
	int		start;
	int		end;
	char	*str;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_isset(s1[start], set))
		start++;
	while (end > start && ft_isset(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	index = 0;
	while (start != end)
	{
		str[index] = s1[start];
		index++;
		start++;
	}
	str[index] = '\0';
	return (str);
}
