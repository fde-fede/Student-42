/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:51:06 by fde-fede          #+#    #+#             */
/*   Updated: 2022/06/04 19:11:57 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"

typedef struct s_game
{
	int				map_width;
	int				map_height;
	int				nb_moves;
	mlx_image_t		*ground;
	mlx_image_t		*collectionable;
	mlx_image_t		*player;
	mlx_image_t		*wall;
	mlx_image_t		*exit;
	char			*map;
	int				total_line_char;
	int				line_number;
	char			*player_position;
	int				nb_exit;
	int				number;
	int				endline;
	int				fd;
	int				x;
	int				y;
}		t_game;

#endif