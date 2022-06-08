/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:51:06 by fde-fede          #+#    #+#             */
/*   Updated: 2022/06/08 17:35:34 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42/MLX42.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_mlx_2
{
	mlx_t		mlx;
	mlx_image_t	img;
}		t_mlx_2;

typedef struct s_game
{
	t_mlx_2			mlx;
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

int		map_init(t_game *game, char *argv);
void	deal_res(int res, t_game *game, char *line, char *whole_chars);
void	init_map_b(t_game *game, char *whole_chars);
void	check_arg(int argc, char *argv[]);
void	checl_map_elements(char	*whole_chars);
void	check_walls(char *line);
void	problems(char *problem, char *whole_chars);

#endif