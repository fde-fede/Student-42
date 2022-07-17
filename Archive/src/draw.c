/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestrada <jestrada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:31:33 by jestrada          #+#    #+#             */
/*   Updated: 2022/05/19 19:43:43 by jestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
*
*	color = 0x009933AA;
*	color = 0x0099ffAA;
*
*/

void	ft_draw_map(t_map *map, mlx_image_t *img)
{
	iso_map(map);
	scale_map(map, 0.8);
	center_map(map);
	draw_map_y(map, img);
	draw_map_x(map, img);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}

void	usage_program(int argc)
{
	if (argc != 2)
	{
		ft_printf("Usage ./fdf (valid map file)\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char const **argv)
{
	t_map	*map;
	t_data	data;

	usage_program(argc);
	data.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data.mlx)
		exit(EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	map = parse_file(argv[1]);
	if (!map)
	{
		ft_printf("Error al leer el mapa\n");
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
