/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:55:48 by fde-fede          #+#    #+#             */
/*   Updated: 2023/04/08 20:18:03 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

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

void		keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	
	game = (t_game *)param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS) || (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS))
		move_up(game);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS) || (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
		move_right(game);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS) || (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS))
		move_left(game);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS) || (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS))
		move_down(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
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
	game->data = malloc(sizeof(t_data));
	if (!check_map(argv[1], game))
		return 0;
	parse_map(argv[1], game);
	set_images(game);
	game->mlx = mlx_init(game->data->width * 40, game->data->height * 40, "So_Long", true);
	game->data->enemy_index = 0;
	print_map(game, game->mlx);
	mlx_key_hook(game->mlx, &keyhook, game);
	mlx_loop_hook(game->mlx, &look_for_move, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
