/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_misc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:39:13 by fde-fede          #+#    #+#             */
/*   Updated: 2022/05/25 20:35:07 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	scale_map(t_map *map, float user_scale)
{
	int			index_x;
	int			index_y;
	float		scale;
	t_vector	d;
	t_vector	d2;

	d = subtraction_vectors(create_vector(4885, 1960, 0),
			create_vector(233, 918, 0));
	d2 = subtraction_vectors(map->map[0][map->size_x - 1], map->map[map->size_y
			- 1][0]);
	scale = sqrt(d.x * d.x + d.y * d.y) / sqrt((d2.x * d2.x) + (d2.y * d2.y));
	index_y = 0;
	while (index_y != map->size_y)
	{
		map->map[index_y][0].x *= (scale * user_scale);
		map->map[index_y][0].y *= (scale * user_scale);
		index_x = 1;
		while (index_x != map->size_x)
		{
			map->map[index_y][index_x].x *= (scale * user_scale);
			map->map[index_y][index_x].y *= (scale * user_scale);
			index_x++;
		}
		index_y++;
	}
}

void	center_map(t_map *map)
{
	int			index_x;
	int			index_y;
	int			move_x;
	int			move_y;
	t_vector	d;

	d = subtraction_vectors(map->map[0][0], map->map[map->size_y
			-1][map->size_x - 1]);
	move_x = (WIDTH / 2) + d.x / 2;
	move_y = (HEIGHT / 2) + d.y / 2;
	index_y = 0;
	while (index_y != map->size_y)
	{
		map->map[index_y][0].x += move_x;
		map->map[index_y][0].y += move_y;
		index_x = 1;
		while (index_x != map->size_x)
		{
			map->map[index_y][index_x].x += move_x;
			map->map[index_y][index_x].y += move_y;
			index_x++;
		}
		index_y++;
	}
}

void	iso(t_vector *vector)
{
	int	prev_x;
	int	prev_y;

	prev_x = vector->x;
	prev_y = vector->y;
	vector->x = (prev_x - prev_y) * cos(0.523599);
	vector->y = (-(vector->z) * 0.1) + (prev_x + prev_y) * sin(0.523599);
}

void	iso_map(t_map *map)
{
	int	index_x;
	int	index_y;

	index_y = 0;
	while (index_y != map->size_y)
	{
		iso(&map->map[index_y][0]);
		index_x = 1;
		while (index_x != map->size_x)
		{
			iso(&map->map[index_y][index_x]);
			index_x++;
		}
		index_y++;
	}
}
