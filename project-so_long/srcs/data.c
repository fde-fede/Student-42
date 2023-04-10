/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:35:51 by fde-fede          #+#    #+#             */
/*   Updated: 2023/04/08 19:49:23 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	check_char(t_game *game, char c, int i, int j)
{
	if (c == 'E')
		game->data->nb_exit++;
	if (c == 'C')
		game->data->collectables++;
	if (c == 'N')
	{
		if (game->data->enemy_index <= game->data->nb_enemies)
		{
			game->data->enemies[game->data->enemy_index].enemy_height = i;
			game->data->enemies[game->data->enemy_index].enemy_width = j;
			game->data->enemy_index++;
		}
	}
	if (c == 'P')
	{
		game->data->playernb++;
		game->data->playerheight = i;
		game->data->playerwidth = j;
	}
}

void	init_data(t_game *game)
{
	game->data->collectables = 0;
	game->data->playernb = 0;
	game->data->nb_exit = 0;
	game->data->counter = 0;
	game->move_time = 0;
}

int	save_data(t_game *game)
{
	int		i;
	int		j;
	
	init_data(game);
	i = 0;
	game->data->enemy_index = 0;
	while (game->data->map[i])
	{
		j = 0;
		while (game->data->map[i][j])
		{
			check_char(game, game->data->map[i][j], i, j);
			j++;
		}
		i++;
	}
	if (game->data->playernb <= 0 || game->data->collectables <= 0 || game->data->nb_exit <= 0)
		return (0);
	if (game->data->playernb > 1 || game->data->nb_exit > 1)
		return (0);
	return (1);
}
