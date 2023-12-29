/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:04:55 by joslopez          #+#    #+#             */
/*   Updated: 2023/07/24 19:08:52 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_floor_ceil_2(t_arg *arg, char *buffer, int i)
{
	while (ft_isdigit(buffer[i]))
		i++;
	while (!ft_isdigit(buffer[i]) && buffer[i] != '-')
		i++;
	if (ft_atoi(buffer + i) > 255 || ft_atoi(buffer + i) < 0)
	{
		ft_putstr("Error\nProblems with floor or ceil");
		return (1);
	}
	if (buffer[0] == 'F')
		arg->floor.b = ft_atoi(buffer + i);
	else
		arg->ceil.b = ft_atoi(buffer + i);
	return (0);
}

int	aux_check_floor_ceil(t_arg *variables, char *buffer, int i)
{
	if (buffer[0] == 'F')
		variables->floor.r = ft_atoi(buffer + i);
	else
		variables->ceil.r = ft_atoi(buffer + i);
	while (ft_isdigit(buffer[i]))
		i++;
	while (!ft_isdigit(buffer[i]) && buffer[i] != '-')
		i++;
	if (ft_atoi(buffer + i) > 255 || ft_atoi(buffer + i) < 0)
	{
		ft_putstr("Error\nProblems with floor or ceil");
		return (1);
	}
	if (buffer[0] == 'F')
		variables->floor.g = ft_atoi(buffer + i);
	else
		variables->ceil.g = ft_atoi(buffer + i);
	return (0);
}

int	check_floor_ceil(t_arg *variables, char *buffer)
{
	int	i;

	i = 0;
	while (!ft_isdigit(buffer[i]) && buffer[i] != '-')
		i++;
	if (ft_atoi(buffer + i) > 255 || ft_atoi(buffer + i) < 0)
	{
		ft_putstr("Error\nProblems with floor or ceil");
		return (1);
	}
	if (aux_check_floor_ceil(variables, buffer, i) != 0)
	{
		ft_putstr("Error\nProblems with floor or ceil");
		return (1);
	}
	if (check_floor_ceil_2(variables, buffer, i) != 0)
	{
		ft_putstr("Error\nProblems with floor or ceil");
		return (1);
	}
	return (0);
}
