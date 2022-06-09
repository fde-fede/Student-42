/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:32:59 by fde-fede          #+#    #+#             */
/*   Updated: 2022/06/09 16:42:08 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	texture_load(t_game *game, mlx_image_t **img, char *path)
{
	xpm_t	*tmp;

	tmp = mlx_load_xpm42(path);
	*img = tmp;
}

void	texture_init(t_game *game)
{
	texture_load(game, &game->player, "./img/link1.xpm");
	texture_load(game, &game->exit, "./img/tent.xpm");
	texture_load(game, &game->collectionable, "./img/key.xpm");
	texture_load(game, &game->wall, "./img/wall.xpm");
	texture_load(game, &game->ground, "./img/ground.xpm");
}

unsigned int	mlx_get_pixel(mlx_image_t *img, int x, int y)
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
