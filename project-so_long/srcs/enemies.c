/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:38:24 by fde-fede          #+#    #+#             */
/*   Updated: 2023/04/09 18:41:13 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int enemy_move_up(t_game *game)
{
	int	i;
	int	j;

	i = game->data->enemies[game->data->enemy_index].enemy_height;
	j = game->data->enemies[game->data->enemy_index].enemy_width;
	if (game->data->map[i - 1][j] == '0')
	{
		game->data->map[i][j] = '0';
		game->data->map[--i][j] = 'N';
		game->data->enemies[game->data->enemy_index].enemy_height--;
		char_to_image(i + 1, j, '0', game, game->mlx);
		imgs_to_window(game->imgs->enemy_up, game->mlx, j, i);
	}
	else if (game->data->map[i - 1][j] == '1')
		enemy_move_left(game);
	else if (game->data->map[i - 1][j] == 'P')
	{
		//todo: animacion muerte
		printf("%s", "You lost!\n");
		mlx_close_window(game->mlx);
		return 0;
	}
	if (game->data->enemy_index == game->data->nb_enemies - 1)
		game->data->enemy_index = 0;
	else
		game->data->enemy_index++;
	return 1;
}

int enemy_move_left(t_game *game)
{
	int	i;
	int	j;

	i = game->data->enemies[game->data->enemy_index].enemy_height;
	j = game->data->enemies[game->data->enemy_index].enemy_width;
	if (game->data->map[i][j - 1] == '0')
	{
		game->data->map[i][j] = '0';
		game->data->map[i][--j] = 'N';
		game->data->enemies[game->data->enemy_index].enemy_width--;
		char_to_image(i, j + 1, '0', game, game->mlx);
		imgs_to_window(game->imgs->enemy_left, game->mlx, j, i);
	}
	else if (game->data->map[i][j - 1] == 'P')
	{
		//todo: animacion muerte
		printf("%s", "You lost!\n");
		mlx_close_window(game->mlx);
		return 0;
	}
	else if (game->data->map[i][j - 1] == '1')
		enemy_move_down(game);
	if (game->data->enemy_index == game->data->nb_enemies - 1)
		game->data->enemy_index = 0;
	else
		game->data->enemy_index++;
	return 1;
}

int enemy_move_right(t_game *game)
{
	int	i;
	int	j;

	i = game->data->enemies[game->data->enemy_index].enemy_height;
	j = game->data->enemies[game->data->enemy_index].enemy_width;
	if (game->data->map[i][j + 1] == '0')
	{
		game->data->map[i][j + 1] = '0';
		game->data->map[i][++j] = 'N';
		game->data->enemies[game->data->enemy_index].enemy_width++;
		char_to_image(i, j - 1, '0', game, game->mlx);
		imgs_to_window(game->imgs->enemy_right, game->mlx, j, i);
	}
	else if (game->data->map[i][j + 1] == 'P')
	{
		//todo: animacion muerte
		printf("%s", "You lost!\n");
		mlx_close_window(game->mlx);
		return 0;
	}
	else if (game->data->map[i][j + 1] == '1')
		enemy_move_up(game);
	if (game->data->enemy_index == game->data->nb_enemies - 1)
		game->data->enemy_index = 0;
	else
		game->data->enemy_index++;
	return 1;
}

int enemy_move_down(t_game *game)
{
	int	i;
	int	j;

	i = game->data->enemies[game->data->enemy_index].enemy_height;
	j = game->data->enemies[game->data->enemy_index].enemy_width;
	if (game->data->map[i + 1][j] == '0')
	{
		game->data->map[i][j] = '0';
		game->data->map[++i][j] = 'N';
		game->data->enemies[game->data->enemy_index].enemy_height++;
		char_to_image(i - 1, j, '0', game, game->mlx);
		imgs_to_window(game->imgs->enemy_down, game->mlx, j, i);
	}
	else if (game->data->map[i + 1][j] == 'P')
	{
		//todo: animacion muerte
		printf("%s", "You lost!\n");
		mlx_close_window(game->mlx);
		return 0;
	}
	else if (game->data->map[i + 1][j] == '1')
		enemy_move_right(game);
	if (game->data->enemy_index == game->data->nb_enemies - 1)
		game->data->enemy_index = 0;
	else
		game->data->enemy_index++;
	return 1;
}

void	look_for_move(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_get_time() > (game->move_time + 0.5))
	{
		game->data->enemy_index = 0;
		while (game->data->enemy_index != game->data->nb_enemies)
		{
			game->move_time = mlx_get_time();
			if (game->data->enemies[game->data->enemy_index].enemy_height < game->data->playerheight)
				enemy_move_down(game);
			else if (game->data->enemies[game->data->enemy_index].enemy_height > game->data->playerheight)
				enemy_move_up(game);
			else if (game->data->enemies[game->data->enemy_index].enemy_width < game->data->playerwidth)
				enemy_move_right(game);
			else if (game->data->enemies[game->data->enemy_index].enemy_width > game->data->playerwidth)
				enemy_move_left(game);
			game->data->enemy_index++;
		}
	}
}
