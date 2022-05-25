/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:43:11 by fde-fede          #+#    #+#             */
/*   Updated: 2022/05/25 20:41:06 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <math.h>

# define WIDTH 5120
# define HEIGHT 2880

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}				t_vector;

typedef struct s_map
{
	int			size_x;
	int			size_y;
	t_vector	**map;
}				t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	t_map		*map;
	mlx_image_t	*img;
}				t_data;

void		ft_draw_map(t_map *map, mlx_image_t *img);
void		iso_map(t_map *map);
void		iso(t_vector *vector);
void		center_map(t_map *map);
t_vector	create_vector(int x, int y, int z);
t_vector	subtraction_vectors(t_vector fst_vector, t_vector scnd_vector);
t_map		*read_file(const char *file);
char		**ft_get_map(const char *map);
char		**ft_join_line_to_map(char **strmap, char *line);
t_map		*ft_set_size_map(t_map *map, char **strmap);
t_map		*ft_mapstr_to_map(t_map *map, char **strmap);
char		*free_strmap(char **strmap);
t_map		*free_map(t_map *map);
void		draw_map_y(t_map *map, mlx_image_t *img);
void		draw_map_x(t_map *map, mlx_image_t *img);
void		draw_line(mlx_image_t *img, t_vector vec1, t_vector vec2,
				int color);
void		fix_draw_vec(t_vector *vec);
void		scale_map(t_map *map, float user_scale);
#endif