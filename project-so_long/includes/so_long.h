/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:24:15 by fde-fede          #+#    #+#             */
/*   Updated: 2023/04/03 16:44:06 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "/Users/felixjr/development/MLX42/include/MLX42/MLX42.h"
# include "/sgoinfre/shared/MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>


typedef struct s_data
{
	char	**map;
	
	int		height;
	int		width;
	int		playernb;
	int		nb_exit;
	int		playerwidth;
	int		playerheight;
	int		counter;
	int		collectables;
}				t_data;

typedef struct s_map
{
	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;
}			t_map;

typedef struct s_game
{
	t_data		*data;
	//t_map		*map;
	//t_images	*imgs;
}				t_game;

typedef struct s_images
{
	mlx_texture_t		*player;
	mlx_texture_t		*collectionable;
	mlx_texture_t		*wall;
	mlx_texture_t		*exit;
	mlx_texture_t		*floor;
}				t_images;


int		parse_map(char *argv, t_game *game);
int		check_map(char *argv, t_game *game);
void	check_char(t_game *game, char c);
void	init_data(t_game *game);
int		save_data(t_game *game);
#endif