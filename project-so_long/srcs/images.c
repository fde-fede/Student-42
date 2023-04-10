/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:49:30 by fde-fede          #+#    #+#             */
/*   Updated: 2023/04/09 15:08:13 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	imgs_to_window(mlx_texture_t *image, mlx_t *mlx, int axis_x, int axis_y)
{
	mlx_image_t *img;
	img = mlx_texture_to_image(mlx, image);
	mlx_image_to_window(mlx, img, axis_x * 40, axis_y * 40);
}

void set_images(t_game *game)
{
	game->imgs = malloc(sizeof(t_images));
	game->imgs->player_down = mlx_load_png("/Users/felixjr/Desktop/42/project-so_long/images/eco_down.png");
	game->imgs->player_up = mlx_load_png("/Users/felixjr/Desktop/42/project-so_long/images/link_up.png");
	game->imgs->player_left = mlx_load_png("/Users/felixjr/Desktop/42/project-so_long/images/eco_left.png");
	game->imgs->player_right = mlx_load_png("/Users/felixjr/Desktop/42/project-so_long/images/eco_right.png");
	game->imgs->collectionable = mlx_load_png("/Users/felixjr/Desktop/42/project-so_long/images/fish.png");
	game->imgs->wall = mlx_load_png("/Users/felixjr/Desktop/42/project-so_long/images/wall.png");
	game->imgs->exit = mlx_load_png("/Users/felixjr/Desktop/42/project-so_long/images/ovillo.png");
	game->imgs->floor = mlx_load_png("/Users/felixjr/Desktop/42/project-so_long/images/ground.png");
	game->imgs->enemy_down = mlx_load_png("/Users/felixjr/Desktop/42/project-so_long/images/limpito_down.png");
	game->imgs->enemy_up = mlx_load_png("/Users/felixjr/Desktop/42/project-so_long/images/limpito_up.png");
	game->imgs->enemy_left = mlx_load_png("/Users/felixjr/Desktop/42/project-so_long/images/limpito_left.png");
	game->imgs->enemy_right = mlx_load_png("/Users/felixjr/Desktop/42/project-so_long/images/limpito_right.png");
}