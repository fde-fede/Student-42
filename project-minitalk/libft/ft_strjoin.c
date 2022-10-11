/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:38:39 by fde-fede          #+#    #+#             */
/*   Updated: 2022/04/26 15:36:59 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	i_s2;

	if (!(s1 && s2))
		return (NULL);
	else if (!s1 || !s2)
	{
		if (!s1)
			return (ft_strdup(s2));
		else
			return (ft_strdup(s1));
	}
	i = ft_strlen(s1);
	i_s2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (i + i_s2 + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, i + 1);
	ft_strlcat(dest + (i), s2, i_s2 + 1);
	return (dest);
}
