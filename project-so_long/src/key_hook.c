/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:23:37 by fde-fede          #+#    #+#             */
/*   Updated: 2022/06/17 13:21:47 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_hook(t_game *game)
{
	free(game->map);
	exit(1);
}

void	is_game_finished(t_game *game)
{
	int	cont;
	int	i;

	cont = 0;
	i = 0;
	if (ft_strchr(game->map, 'E') == NULL)
	{
		if (game->nb_exit <= 1)
			if (ft_strchr(game->map, 'X') == NULL)
				exit_hook(game);
		while (game->map[i])
		{
			if (game->map[i] == 'X')
				cont++;
			i++;
		}
		if (cont == game->nb_exit - 1)
			exit_hook(game);
	}
}

int	reduce_window(t_game *game)
{
	draw_map(game);
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	if (ft_strchr(game->map, 'C') == NULL)
	{
		while (ft_strchr(game->map, 'E'))
		{
			game->nb_exit++;
			*ft_strchr(game->map, 'E') = 'X';
		}
	}
	if (keycode == MLX_KEY_ESCAPE)
		exit_hook(game);
	if (keycode == MLX_KEY_W)
		move_up(game);
	if (keycode == MLX_KEY_S)
		move_bottom(game);
	if (keycode == MLX_KEY_A)
		move_left(game);
	if (keycode == MLX_KEY_D)
		move_right(game);
	is_game_finished(game);
	draw_map(game);
	return (1);
}
