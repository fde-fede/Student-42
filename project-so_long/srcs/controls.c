/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:26:01 by fde-fede          #+#    #+#             */
/*   Updated: 2023/04/09 18:46:09 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game)
{
	int	i;
	int	j;

	i = game->data->playerheight;
	j = game->data->playerwidth;
	if (game->data->map[i - 1][j] == 'C')
	{
		game->data->map[i - 1][j] = 'P';
		game->data->map[i][j] = '0';
		game->data->playerheight--;
		game->data->collectables--;
		game->data->counter++;
		printf("%s", "Movements: ");
		printf("%i", game->data->counter);
		printf("%c", '\n');
		char_to_image(i, j, game->data->map[i][j], game, game->mlx);
		imgs_to_window(game->imgs->player_left, game->mlx, j, i - 1);
		return (1);
	}
	if (game->data->map[i - 1][j] == 'E')
	{
		if (game->data->collectables == 0)
		{
			mlx_close_window(game->mlx);
			printf("%s", "Congrats! You win!\n");
			return (1);
		}
	}
	if (game->data->map[i- 1][j] == 'N')
	{
		mlx_close_window(game->mlx);
		printf("%s", "You lose!\n");
		return (1);
	}
	if (game->data->map[i - 1][j] == '0')
	{
		game->data->map[i - 1][j] = 'P';
		game->data->map[i][j] = '0';
		game->data->playerheight--;
		game->data->counter++;
		printf("%s", "Movements: ");
		printf("%i", game->data->counter);
		printf("%c", '\n');
		char_to_image(i, j, game->data->map[i][j], game, game->mlx);
		imgs_to_window(game->imgs->player_left, game->mlx, j, i - 1);
		return (1);
	}
	return (0);
}
int	move_left(t_game *game)
{
	int	i;
	int	j;

	i = game->data->playerheight;
	j = game->data->playerwidth;
		if (game->data->map[i][j - 1] == 'C')
	{
		game->data->map[i][j - 1] = 'P';
		game->data->map[i][j] = '0';
		game->data->playerwidth--;
		game->data->collectables--;
		game->data->counter++;
		printf("%s", "Movements: ");
		printf("%i", game->data->counter);
		printf("%c", '\n');
		char_to_image(i, j, game->data->map[i][j], game, game->mlx);
		imgs_to_window(game->imgs->player_left, game->mlx, j - 1, i);
		return (1);
	}
	if (game->data->map[i][j - 1] == 'E')
	{
		if (game->data->collectables == 0)
		{
			mlx_close_window(game->mlx);
			printf("%s", "Congrats! You win!\n");
			return (1);
		}
	}
	if (game->data->map[i][j - 1] == 'N')
	{
		mlx_close_window(game->mlx);
		printf("%s", "You lose!\n");
		return (1);
	}
	if (game->data->map[i][j - 1] == '0')
	{
		game->data->map[i][j - 1] = 'P';
		game->data->map[i][j] = '0';
		game->data->playerwidth--;
		game->data->counter++;
		printf("%s", "Movements: ");
		printf("%i", game->data->counter);
		printf("%c", '\n');
		char_to_image(i, j, game->data->map[i][j], game, game->mlx);
		imgs_to_window(game->imgs->player_left, game->mlx, j - 1, i);
		return (1);
	}
	return (0);
}
int	move_right(t_game *game)
{
	int	i;
	int	j;

	i = game->data->playerheight;
	j = game->data->playerwidth;
	if (game->data->map[i][j + 1] == 'C')
	{
		game->data->map[i][j + 1] = 'P';
		game->data->map[i][j] = '0';
		game->data->playerwidth++;
		game->data->collectables--;
		game->data->counter++;
		printf("%s", "Movements: ");
		printf("%i", game->data->counter);
		printf("%c", '\n');
		char_to_image(i, j, game->data->map[i][j], game, game->mlx);
		imgs_to_window(game->imgs->player_right, game->mlx, j + 1, i);
		return (1);
	}
	if (game->data->map[i][j + 1] == 'E')
	{
		if (game->data->collectables == 0)
		{
			mlx_close_window(game->mlx);
			printf("%s", "Congrats! You win!\n");
			return (1);
		}
	}
	if (game->data->map[i][j + 1] == 'N')
	{
		mlx_close_window(game->mlx);
		printf("%s", "You lose!\n");
		return (1);
	}
	if (game->data->map[i][j + 1] == '0')
	{
		game->data->map[i][j + 1] = 'P';
		game->data->map[i][j] = '0';
		game->data->playerwidth++;
		game->data->counter++;
		printf("%s", "Movements: ");
		printf("%i", game->data->counter);
		printf("%c", '\n');
		char_to_image(i, j, game->data->map[i][j], game, game->mlx);
		imgs_to_window(game->imgs->player_right, game->mlx, j + 1, i);
		return (1);
	}
	return (0);
}
int	move_down(t_game *game)
{
	int	i;
	int	j;

	i = game->data->playerheight;
	j = game->data->playerwidth;
		if (game->data->map[i + 1][j] == 'C')
	{
		game->data->map[i + 1][j] = 'P';
		game->data->map[i][j] = '0';
		game->data->playerheight++;
		game->data->collectables--;
		game->data->counter++;
		printf("%s", "Movements: ");
		printf("%i", game->data->counter);
		printf("%c", '\n');
		char_to_image(i, j, game->data->map[i][j], game, game->mlx);
		imgs_to_window(game->imgs->player_down, game->mlx, j, i + 1);
		return (1);
	}
	if (game->data->map[i + 1][j] == 'E')
	{
		if (game->data->collectables == 0)
		{
			mlx_close_window(game->mlx);
			printf("%s", "Congrats! You win!\n");
			return (1);
		}
	}
	if (game->data->map[i + 1][j] == 'N')
	{
		mlx_close_window(game->mlx);
		printf("%s", "You lose!\n");
		return (1);
	}
	if (game->data->map[i + 1][j] == '0')
	{
		game->data->map[i + 1][j] = 'P';
		game->data->map[i][j] = '0';
		game->data->playerheight++;
		game->data->counter++;
		printf("%s", "Movements: ");
		printf("%i", game->data->counter);
		printf("%c", '\n');
		char_to_image(i, j, game->data->map[i][j], game, game->mlx);
		imgs_to_window(game->imgs->player_down, game->mlx, j, i + 1);
		return (1);
	}
	return (0);
}
