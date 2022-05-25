/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 19:43:44 by fde-fede          #+#    #+#             */
/*   Updated: 2022/05/25 20:34:53 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <memory.h>

t_map	*free_map(t_map *map)
{
	int	index_x;
	int	index_y;

	index_x = 0;
	index_y = 0;
	while (index_y != map->size_y)
	{
		free(map->map[index_y]);
		index_y++;
	}
	free(map->map);
	free(map);
	return (NULL);
}

char	*free_strmap(char **strmap)
{
	int	index;

	index = 0;
	while (strmap[index] != NULL)
	{
		free(strmap[index]);
		index++;
	}
	free(strmap);
	return (NULL);
}

void	hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		data->img->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		data->img->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		data->img->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		data->img->instances[0].x += 5;
}

void	ft_draw_map(t_map *map, mlx_image_t *img)
{
	iso_map(map);
	scale_map(map, 0.8);
	center_map(map);
	draw_map_y(map, img);
	draw_map_x(map, img);
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_data	data;

	if (argc != 2)
	{
		ft_printf("%s\n", "Usage error");
		exit(EXIT_FAILURE);
	}
	data.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data.mlx)
		exit(EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	map = read_file(argv[1]);
	if (!map)
	{
		ft_printf("%s\n", "Error al leer el mapa!");
		exit(EXIT_FAILURE);
	}
	ft_draw_map(map, data.img);
	mlx_loop_hook(data.mlx, &hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	free_map(map);
	return (EXIT_SUCCESS);
}
