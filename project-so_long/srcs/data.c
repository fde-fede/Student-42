/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:35:51 by fde-fede          #+#    #+#             */
/*   Updated: 2023/04/03 16:42:48 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	check_char(t_game *game, char c)
{
	if (c == 'E')
		game->data->nb_exit++;
	if (c == 'C')
		game->data->collectables++;
	if (c == 'P')
		game->data->playernb++;
}

void	init_data(t_game *game)
{
	game->data->collectables = 0;
	game->data->playernb = 0;
	game->data->nb_exit = 0;
	game->data->playerwidth = 0;
	game->data->playerheight = 0;
	game->data->counter = 0;
}

int	save_data(t_game *game)
{
	int		i;
	int		j;
	
	init_data(game);
	i = 0;
	while (game->data->map[i])
	{
		j = 0;
		while (game->data->map[i][j])
		{
			check_char(game, game->data->map[i][j]);
			j++;
		}
		i++;
	}
	return (1);
}