/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:42:34 by fde-fede          #+#    #+#             */
/*   Updated: 2022/06/17 13:20:09 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_square(t_game *game, mlx_image_t *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			mlx_put_pixel(game->mlx.img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	check_for_elements(t_game *game, int x, int y, int z)
{
	if (game->map[z + game->number] == 'P')
		draw_square(game, game->player, x, y * 39);
	if (game->map[z + game->number] == 'C')
		draw_square(game, game->collectionable, x, y * 39);
	if (game->map[z + game->number] == 'E'
		|| game->map[z + game->number] == 'X')
		draw_square(game, game->exit, x, y * 39);
}

void	draw_map(t_game *game)
{
	int	z;

	game->number = 0;
	game->y = 0;
	game->x = -40;
	while (game->y < (game->line_number - 1))
	{
		z = 0;
		while (z < game->total_line_char)
		{
			if (game->map[z + game->number] == '1')
				draw_square(game, game->wall, game->x += 40, game->y * 39);
			else
			{
				draw_square(game, game->ground, game->x += 40, game->y * 39);
				check_for_elements(game, game->x, game->y, z);
			}
			z++;
		}
		game->y++;
		game->number = game->total_line_char * game->y;
	}
	mlx_image_to_window(game->mlx.mlx, game->mlx.img, 0, 0);
}
