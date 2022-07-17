/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestrada <jestrada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:52:30 by jestrada          #+#    #+#             */
/*   Updated: 2022/05/19 19:11:00 by jestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_vec
{
	float		x;
	float		y;
	float		z;
}				t_vec;

typedef struct s_map
{
	int			size_x;
	int			size_y;
	t_vec		**map;
}				t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	t_map		*map;
	mlx_image_t	*img;
}				t_data;

t_vec			subtraction_vectors(t_vec vec1, t_vec vec2);
t_vec			create_vector(int x, int y, int z);

t_map			*parse_file(const char *file);
t_map			*free_map(t_map *map);
char			*free_strmap(char **strmap);

void			iso_map(t_map *map);
void			scale_map(t_map *map, float user_scale);
void			center_map(t_map *map);

void			draw_map_x(t_map *map, mlx_image_t *img);
void			draw_map_y(t_map *map, mlx_image_t *img);

#endif