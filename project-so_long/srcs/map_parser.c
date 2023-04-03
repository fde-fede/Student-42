/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:17:00 by fde-fede          #+#    #+#             */
/*   Updated: 2023/04/02 15:16:33 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int parse_map(char *argv, t_game *game)
{
	int	i = 0;
	int j = 0;
	int	fd;

	game->data->map = (char **)malloc(sizeof(char *) * (9999));
	fd = open(argv, O_RDONLY);
	while (i <= 9)
	{
		game->data->map[i] = malloc(sizeof(char) * 999);
		game->data->map[i] = get_next_line(fd);
		i++;
	}
	i = 0;
	close(fd);
	while(game->data->map[i])
	{
		j = 0;
		while (game->data->map[i][j])
		{
			write(1, &game->data->map[i][j], 1);
			j++;
		}
	i++;
	}
	return (1);
}
// lectura mapa, guardado de datos y comprobar camino valido
