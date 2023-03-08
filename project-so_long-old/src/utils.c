/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:32:59 by fde-fede          #+#    #+#             */
/*   Updated: 2022/06/17 18:18:13 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	texture_load(t_game *game, mlx_image_t **img, char *path)
{
	mlx_texture_t	*temp;

	temp = mlx_load_png(path);
	*img = mlx_texture_to_image(game->mlx.mlx, temp);
	free(temp);
}

void	texture_init(t_game *game)
{
	texture_load(game, &game->player, "./img/link1.png");
	texture_load(game, &game->exit, "./img/tent.png");
	texture_load(game, &game->collectionable, "./img/key.png");
	texture_load(game, &game->wall, "./img/wall.png");
	texture_load(game, &game->ground, "./img/ground.png");
}

unsigned int	mlx_get_pixel(mlx_image_t *img, unsigned int x, unsigned int y)
{
	unsigned int	*pixel;

	if (x >= img->width)
		x = img->width - 1;
	if (y >= img->height)
		y = img->height - 1;
	pixel = (unsigned int *)(img->pixels
			+ (x + y * img->width) * sizeof(unsigned int));
	return (*pixel);
}
