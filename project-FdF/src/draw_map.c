/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:37:21 by fde-fede          #+#    #+#             */
/*   Updated: 2022/05/26 21:47:25 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fix_draw_vec(t_vector *vec)
{
	if (vec->x <= 0)
		vec->x = 1;
	if (vec->x >= WIDTH)
		vec->x = WIDTH - 1;
	if (vec->y <= 0)
		vec->y = 1;
	if (vec->y >= HEIGHT)
		vec->y = HEIGHT - 1;
}

void	draw_line(mlx_image_t *img, t_vector vec1, t_vector vec2, int color)
{
	t_vector	d;
	t_vector	p;
	int			pixels;

	fix_draw_vec(&vec1);
	fix_draw_vec(&vec2);
	d = subtraction_vectors(vec2, vec1);
	pixels = sqrt((d.x * d.x) + (d.y * d.y));
	p = vec1;
	d.x /= pixels;
	d.y /= pixels;
	while (pixels)
	{
		mlx_put_pixel(img, (int)round(p.x), (int)round(p.y), color);
		p.x += d.x;
		p.y += d.y;
		pixels--;
	}
}

void	draw_map_x(t_map *map, mlx_image_t *img)
{
	int	index_y;
	int	index_x;
	int	color;

	index_y = 0;
	index_x = 0;
	while (index_x != map->size_x)
	{
		index_y = 1;
		while (index_y != map->size_y)
		{
			if (map->map[index_y][index_x].z >= 1 || map->map[index_y
				- 1][index_x].z >= 1)
				color = 0x009933AA;
			else
				color = 0x0099ffAA;
			draw_line(img, map->map[index_y - 1][index_x],
				map->map[index_y][index_x], color);
			index_y++;
		}
		index_x++;
	}
}

void	draw_map_y(t_map *map, mlx_image_t *img)
{
	int	index_y;
	int	index_x;
	int	color;

	index_y = 0;
	while (index_y != map->size_y)
	{
		index_x = 1;
		while (index_x != map->size_x)
		{
			if (map->map[index_y][index_x].z >= 1 || map->map[index_y][index_x
				- 1].z >= 1)
				color = 0x009933AA;
			else
				color = 0x0099ffAA;
			draw_line(img, map->map[index_y][index_x - 1],
				map->map[index_y][index_x], color);
			index_x++;
		}
		index_y++;
	}
}
