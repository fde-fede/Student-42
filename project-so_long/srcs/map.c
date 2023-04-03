/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:43:11 by fde-fede          #+#    #+#             */
/*   Updated: 2023/04/03 17:02:02 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int check_map(char *argv, t_game *game)
{
	char	**map;
	int		i;
	int		fd;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (999));
	fd = open(argv, O_RDONLY);
	while (i >= 0)
	{
		map[i] = malloc(sizeof(char) * 999);
		if (!(map[i] = get_next_line(fd)))
			break;
		i++;
	}
	close (fd);
	i = 0;
	fd = 0;
	while (map[i][fd])
		fd++;
	game->data->width = fd;
	while (i >= 0)
	{
		fd = 0;
		if (!map[i])
			break;
		while (map[i][fd])
			fd++;
		if (fd != game->data->width)
			return 0;
		i++;
	}
	free(map);
	game->data->height = i;
	if (game->data->height == game->data->width)
		return 0;
	return 1;
}
