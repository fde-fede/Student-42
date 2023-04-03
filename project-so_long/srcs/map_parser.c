/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:17:00 by fde-fede          #+#    #+#             */
/*   Updated: 2023/04/03 17:46:49 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int parse_map(char *argv, t_game *game)
{
	int	i = 0;
	int j = 0;
	int	fd;

	game->data->map = (char **)malloc(sizeof(char *) * (game->data->height + 1));
	fd = open(argv, O_RDONLY);
	while (i <= game->data->height)
	{
		game->data->map[i] = malloc(sizeof(char) * (game->data->width + 1));
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
			if (i == 0 || j == 0)
				if (game->data->map[i][j] != '1' && game->data->map[i][j] != '\n')
					return 0;
			j++;
		}
	i++;
	}
	save_data(game);
	return (1);
}
// lectura mapa, guardado de datos y comprobar camino valido
