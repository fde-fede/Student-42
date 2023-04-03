/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:55:48 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/31 13:53:55 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#define WIDTH	1920
#define HEIGHT	1080

int	check_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	temp = malloc(sizeof(char) * 100);
	i = 0;
	j = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i] != '.')
		i++;
	while (argv[1][i])
	{
		temp[j] = argv[1][i];
		j++;
		i++;
	}
	if (strcmp(temp, ".ber"))
		return (0);
	return (1);
}

int32_t	main(int argc, char **argv)
{
	if (!check_args(argc, argv))
	{
		printf("%s", "Arguments error");
		return (0);
	}
	t_game	*game;
	game = malloc(sizeof(t_game));
	// TO DO: leer mapa para hacer malloc perfecto, luego guardar datos y contar el numero de objetos. Comprobar que mapa no es cuadrado
	game->data = malloc(sizeof(t_data));
	parse_map(argv[1], game);

 	/* mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "So_Long", true);
	if (!mlx)
		return 0;

	mlx_image_t* img = mlx_new_image(mlx, 40, 40);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return 0;

	mlx_texture_t *cat;
	cat = mlx_load_png("/Users/fde-fede/Student-42/project-so_long/images/cat.png");
	if (!cat)
		printf("%s", "fallo");

	img = mlx_texture_to_image(mlx, cat);
	mlx_image_to_window(mlx, img, 700, 766/2);

	mlx_loop(mlx);
	mlx_terminate(mlx);
 */	return (EXIT_SUCCESS); 
}
