/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:10:30 by fde-fede          #+#    #+#             */
/*   Updated: 2022/04/25 17:04:10 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	tot_size;

	tot_size = size * count;
	p = malloc(tot_size);
	if (!p)
		return (0);
	ft_memset(p, 0, tot_size);
	return (p);
}
