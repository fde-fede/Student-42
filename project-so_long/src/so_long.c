/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:50:43 by fde-fede          #+#    #+#             */
/*   Updated: 2022/06/08 17:50:28 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map_b(t_game *game, char *whole_chars)
{
	if ((ft_strchr(whole_chars, 'P') == NULL)
		|| (ft_strchr(whole_chars, 'E') == NULL)
		|| (ft_strchr(whole_chars, 'C') == NULL))
		problems("Error\nMissing one variable", whole_chars);
	if (game->line_number - 1 == game->total_line_char)
		problems("Error\nMap is square!", whole_chars);
	check_map_elements(whole_chars);
	game->map_height = (game->line_number - 1) * 40;
	game->map_width = game->total_line_char * 40;
	game->map = malloc(sizeof(char)
			* (game->total_line_char * game->line_number));
	ft_strlcpy(game->map, whole_chars,
		(game->line_number * game->total_line_char));
	game->fd = close(game->fd);
	free(whole_chars);
}

void	deal_res(int res, t_game *game, char *line, char *whole_chars)
{
	while (res > 0)
	{
		game->line_number++;
		game->endline = ft_strlen(line) - 1;
		if (line[0] != '1' || line[game->endline] != '1')
			problems("Error\nWall missing in the border", whole_chars);
		ft_strcat(whole_chars, line);
		free(line);
		line = 0;
		res = get_next_line(game->fd, &line);
		if ((res != 0) && (strlen(line)
				!= (long unsigned int)game->total_line_char))
			problems("Error\nThere is a problem with map", whole_chars);
		if (res == 0)
		{
			game->line_number++;
			check_walls(line);
			ft_strcat(whole_chars, line);
			free(line);
			line = 0;
		}
	}
}

int	map_init(t_game *game, char *argv)
{
	char	*line;
	char	*whole_chars;

	whole_chars = malloc(sizeof(char) * 999999);
	*whole_chars = 0;
	game->line_number = 0;
	game->fd = open(argv, O_RDONLY);
	if (!game->fd)
		problems("Error\nfile cannot be read", whole_chars);
	line = get_next_line(game->fd);
	check_walls(line);
	game->total_line_char = strlen(line);
	deal_res(res, game, line, whole_chars);
	init_map_b(game, whole_chars);
	return (1);
}

/* int	struct_init(t_game *game)
{
	game->nb_exit = 0;
	game->nb_moves = 0;
	game->mlx.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	game->mlx.img. = mlx_new_image(game->mlx.mlx,
			WIDTH, HEIGHT);
}
*/

int	main(int argc, char *argv[])
{
	t_game	game;

	check_arg(argc, argv);
	map_init(&game, argv[1]);
	struc_init(&game);
}
