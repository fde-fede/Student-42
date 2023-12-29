/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:22:46 by joslopez          #+#    #+#             */
/*   Updated: 2023/12/14 20:33:56 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_middle_lines(t_map *map)
{
	t_map	*tmp;
	size_t	len;

	tmp = map;
	aux = map;
	if (!tmp)
	{
		ft_putstr("Error\nInvalid map.");
		return (1);
	}
	while (tmp)
	{
		len = ft_strlen(tmp->line);
		aux = aux->next;
		//printf("%s\n", tmp->line);
		//printf("%s\n", aux->line);
		if ((tmp->line[0] != '1' && tmp->line[0] != ' ') || tmp->line[len \
			- 1] != '1' || (aux && aux->line[len - 1] == '0'))
		{
			ft_putstr("Error\nMap not closed");
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_last_line(t_map *map, int i)
{
	t_map	*tmp;
	t_map	*prev;

	tmp = map;
	if (!tmp)
	{
		ft_putstr("Error\nInvalid map.");
		return (1);
	}
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	while (tmp->line[i])
	{
		if (tmp->line[i] != '1' && tmp->line[i] != ' ' || (prev->line[i] == '0' \
				&& tmp->line[i] != '1'))
		{
			ft_putstr("Error\nLast Map Line not closed.");
			return (1);
		}
		i++;
	}
	return (0);
}

int	closed_map(t_map *map)
{
	t_map	*tmp;
	int		i;

	tmp = map;
	i = 0;
	if (!tmp)
	{
		ft_putstr("Error\nInvalid map.");
		return (1);
	}
	while (tmp->line[i])
	{
		if (tmp->line[i] != '1' && !ft_strchr("\t\v\r\f\n ", tmp->line[i]))
		{
			ft_putstr("Error\nFirst Map Line not closed.");
			return (1);
		}
		i++;
	}
	if (check_middle_lines(map) != 0)
		return (1);
	if (check_last_line(map, 0) != 0)
		return (1);
	return (0);
}

int	validate_and_count_positions(t_map *map, int *count_pos)
{
	t_map	*tmp;
	int		i;

	tmp = map;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (!ft_strchr("01NSWE ", tmp->line[i]))
			{
				ft_putstr("Error\nInvalid character in the map.");
				return (1);
			}
			if (ft_strchr("NSWE", tmp->line[i]) && ++(*count_pos) > 1)
			{
				ft_putstr("Error\nSeveral positions entered in the map.");
				return (1);
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_map(t_map *map)
{
	int	count_pos;
	
	count_pos = 0;
	if (closed_map(map) != 0)
		return (1);
	if (validate_and_count_positions(map, &count_pos) == 1)
		return (1);
	if (count_pos == 0)
	{
		ft_putstr("Error\nNo position was entered in the map.");
		return (1);
	}
	return (0);
}
