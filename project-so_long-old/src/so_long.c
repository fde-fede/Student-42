/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:50:43 by fde-fede          #+#    #+#             */
/*   Updated: 2022/06/17 17:31:55 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map2(t_game *game, char *whole_chars)
{
	if ((ft_strchr(whole_chars, 'P') == NULL)
		|| (ft_strchr(whole_chars, 'E') == NULL)
		|| (ft_strchr(whole_chars, 'C') == NULL))
		problems("Error\nMissing one variable", whole_chars);
	if (game->line_number - 1 == game->total_line_char)
		problems("Error\nMap is a square!!", whole_chars);
	check_map_elements(whole_chars);
	game->map_height = (game->line_number - 1) * 40;
	game->map_width = game->total_line_char * 40;
	game->map = malloc(sizeof(char)
			* (game->total_line_char * game->line_number) + 1);
	ft_strlcpy(game->map, whole_chars,
		(game->line_number * game->total_line_char));
	game->fd = close(game->fd);
	free(whole_chars);
}

void	check_map(t_game *game, char *line, char *whole_chars)
{
	char	*tmp;

	while (line)
	{
		game->line_number++;
		tmp = ft_strtrim(line, "\n");
		if (tmp[0] != '1' || tmp[game->endline] != '1')
			problems("Error\nWall missing in border", line);
		ft_strcat(whole_chars, line);
		free(line);
		line = get_next_line(game->fd);
		if (ft_strlen(line) != (unsigned long)(game->total_line_char))
			problems("Error\nMap has a problem", whole_chars);
	}
}

int	map_init(t_game *game, char *map_name)
{
	char	*line;
	char	*tmp;
	char	*whole_chars;

	whole_chars = malloc(sizeof(char) * 9999999);
	game->fd = open(map_name, O_RDONLY);
	if (!game->fd)
		problems("Error\nFile cannot be read", whole_chars);
	line = get_next_line(game->fd);
	ft_strcat(whole_chars, line);
	tmp = ft_strtrim(line, "\n");
	check_walls(tmp);
	game->total_line_char = ft_strlen(tmp);
	check_map(game, line, whole_chars);
	init_map2(game, whole_chars);
	return (1);
}

int	struct_init(t_game *game)
{
	game->nb_exit = 0;
	game->nb_moves = 0;
	game->mlx.mlx = mlx_init(WIDTH, HEIGHT, "SO_LONG", false);
	game->mlx.img = mlx_new_image(game->mlx.mlx, WIDTH, HEIGHT);
	texture_init(game);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	check_arg(argc, argv);
	map_init(&game, argv[1]);
	struct_init(&game);
	draw_map(&game);
}
