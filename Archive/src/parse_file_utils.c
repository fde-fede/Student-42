/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestrada <jestrada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:28:24 by jestrada          #+#    #+#             */
/*   Updated: 2022/05/19 19:09:24 by jestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*free_map(t_map *map)
{
	int	index_y;
	int	index_x;

	index_y = 0;
	index_x = 0;
	index_y = 0;
	while (index_y != map->size_y)
	{
		free(map->map[index_y]);
		index_y++;
	}
	free(map->map);
	free(map);
	return (NULL);
}

char	*free_strmap(char **strmap)
{
	int	index;

	index = 0;
	while (strmap[index] != NULL)
	{
		free(strmap[index]);
		index++;
	}
	free(strmap);
	return (NULL);
}
