/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:43:11 by fde-fede          #+#    #+#             */
/*   Updated: 2023/04/09 18:47:14 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int check_map(char *argv, t_game *game)
{
	char	**map;
	int		i;
	int		fd;

	i = 0;
	game->data->nb_enemies = 0;
	map = (char **)malloc(sizeof(char *) * (999));
	fd = open(argv, O_RDONLY);
	while (i >= 0)
	{
		map[i] = malloc(sizeof(char) * 999);
		if (!(map[i] = get_next_line(fd)))
			break;
		i++;
	}
	close (fd);
	i = 0;
	fd = 0;
	while (map[i][fd])
		fd++;
	game->data->width = (fd - 1);
	while (i >= 0)
	{
		fd = 0;
		if (!map[i])
			break;
		while (map[i][fd])
		{
			if (map[i][fd] == 'N')
				game->data->nb_enemies++;
			fd++;
		}
		if (fd != game->data->width + 1)
			return 0;
		i++;
	}
	free(map);
	game->data->height = i;
	if (game->data->height == game->data->width)
		return 0;
	return 1;
}

void	char_to_image(int i, int j, char c, t_game *game, mlx_t *mlx)
{
	if (c == '1')
		imgs_to_window(game->imgs->wall, mlx, j, i);
	else if (c == '0')
		imgs_to_window(game->imgs->floor, mlx, j, i);
	else if (c == 'E')
		imgs_to_window(game->imgs->exit, mlx, j, i);
	else if (c == 'P')
		imgs_to_window(game->imgs->player_down, mlx, j, i);
	else if (c == 'C')
		imgs_to_window(game->imgs->collectionable, mlx, j, i);
	else if (c == 'N')
		imgs_to_window(game->imgs->enemy_down, mlx, j, i);
}

void	print_map(t_game *game, mlx_t *mlx)
{
	int	i;
	int	j;
	
	i = 0;
	while (game->data->map[i])
	{
		j = 0;
		while(game->data->map[i][j])
		{
			char_to_image(i, j, game->data->map[i][j], game, mlx);
			j++;
		}
		i++;
	}
}
