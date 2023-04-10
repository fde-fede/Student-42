/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:24:15 by fde-fede          #+#    #+#             */
/*   Updated: 2023/04/09 18:42:23 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
//# include "/sgoinfre/shared/MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct s_enemy
{
	int		enemy_width;
	int		enemy_height;
}		t_enemy;

typedef struct s_data
{
	char	**map;
	
	t_enemy	enemies[10];
	int		enemy_index;
	int		nb_enemies;
	int		height;
	int		width;
	int		playernb;
	int		nb_exit;
	int		counter;
	int		collectables;
	int		playerwidth;
	int		playerheight;
}				t_data;

typedef struct s_images
{
	mlx_texture_t		*player_down;
	mlx_texture_t		*player_up;
	mlx_texture_t		*player_right;
	mlx_texture_t		*player_left;
	mlx_texture_t		*collectionable;
	mlx_texture_t		*wall;
	mlx_texture_t		*exit;
	mlx_texture_t		*floor;
	mlx_texture_t		*enemy_left;
	mlx_texture_t		*enemy_right;
	mlx_texture_t		*enemy_up;
	mlx_texture_t		*enemy_down;
}				t_images;

typedef struct s_game
{
	t_data		*data;
	t_images	*imgs;
	mlx_t		*mlx;
	double		move_time;
}				t_game;

int		parse_map(char *argv, t_game *game);
int		check_map(char *argv, t_game *game);
void	check_char(t_game *game, char c, int i, int j);
void	init_data(t_game *game);
int		save_data(t_game *game);
void	set_images(t_game *game);
void	imgs_to_window(mlx_texture_t *image, mlx_t *mlx, int axis_x, int axis_y);
void	print_map(t_game *game, mlx_t *mlx);
void	char_to_image(int i, int j, char c, t_game *game, mlx_t *mlx);
int		move_up(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
int		move_down(t_game *game);
void	look_for_move(void *param);
int 	enemy_move_up(t_game *game);
int 	enemy_move_down(t_game *game);
int 	enemy_move_left(t_game *game);
int 	enemy_move_right(t_game *game);
#endif