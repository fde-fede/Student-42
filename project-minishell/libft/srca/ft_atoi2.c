/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:52:48 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/11 12:38:24 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_atoi2(const char *nptr, long *nbr)
{
	int		sign;

	sign = 1;
	*nbr = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -sign;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	if (!ft_isdigit(*nptr))
		return (-1);
	while (ft_isdigit(*nptr))
	{
		*nbr = 10 * *nbr + (*nptr - '0');
		if (*nbr > 2147483647 && sign == 1)
			return (-1);
		if (*nbr > 2147483648 && sign == -1)
			return (-1);
		nptr++;
	}
	if (*nptr && !ft_isspace(*nptr))
		return (-1);
	*nbr *= sign;
	return (0);
}
