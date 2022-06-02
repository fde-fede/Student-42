/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 19:43:44 by fde-fede          #+#    #+#             */
/*   Updated: 2022/06/02 18:57:05 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*free_map(t_map *map)
{
	int	index_y;

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

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
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
		ft_printf("Usage error\n");
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
		ft_printf("Error al leer el mapa!\n");
		exit(EXIT_FAILURE);
	}
	ft_draw_map(map, data.img);
	mlx_key_hook(data.mlx, &keyhook, &data);
	mlx_loop(data.mlx);
	mlx_delete_image(data.mlx, data.img);
	mlx_terminate(data.mlx);
	free_map(map);
	return (EXIT_SUCCESS);
}
