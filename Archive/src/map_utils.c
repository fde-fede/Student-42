/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestrada <jestrada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:05:03 by jestrada          #+#    #+#             */
/*   Updated: 2022/05/19 19:27:10 by jestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	scale_map(t_map *map, float user_scale)
{
	int		index_y;
	int		index_x;
	float	scale;
	t_vec	d;
	t_vec	d2;

	d = subtraction_vectors(create_vector(1832, 735, 0), create_vector(86, 343,
				0));
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
	int		index_y;
	int		index_x;
	int		move_x;
	int		move_y;
	t_vec	d;

	d = subtraction_vectors(map->map[0][0], map->map[map->size_y
			- 1][map->size_x - 1]);
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

void	iso(t_vec *vec)
{
	int	previous_x;
	int	previous_y;

	previous_x = vec->x;
	previous_y = vec->y;
	vec->x = (previous_x - previous_y) * cos(0.523599);
	vec->y = (-(vec->z) * 0.1) + (previous_x + previous_y) * sin(0.523599);
}

void	iso_map(t_map *map)
{
	int	index_y;
	int	index_x;

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
