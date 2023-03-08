/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:08:51 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/22 17:17:53 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	int		str_length;
	char	*str_copy;
	char	*ret;

	str_length = ft_strlen(s);
	str_copy = (char *)malloc(sizeof(char) * (str_length + 1));
	if (!str_copy)
		return (NULL);
	ret = str_copy;
	while (*s != '\0')
	{
		*str_copy = *s;
		s++;
		str_copy++;
	}
	*str_copy = '\0';
	return (ret);
}
