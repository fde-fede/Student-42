/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:38:24 by fde-fede          #+#    #+#             */
/*   Updated: 2022/06/17 13:20:59 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_bottom(t_game *game)
{
	char	*ptr;
	int		i;

	ptr = ft_strchr(game->map, 'P');
	i = -1;
	while (++i < game->total_line_char)
		++ptr;
	if (*ptr != '1' && *ptr != 'E')
	{
		*ptr = 'P';
		ptr = ft_strchr(game->map, 'P');
		*ptr = '0';
		game->nb_moves += 1;
		ft_putnbr_fd(game->nb_moves, 1);
		ft_putchar_fd('\n', 1);
	}
	mlx_delete_image(game->mlx.mlx, game->player);
	texture_load(game, &game->player, "./img/link.png");
}

void	move_up(t_game *game)
{
	char	*ptr;
	int		i;

	ptr = ft_strchr(game->map, 'P');
	i = -1;
	while (++i < game->total_line_char)
		--ptr;
	if (*ptr != '1' && *ptr != 'E')
	{
		*ptr = 'P';
		while (--i >= 0)
			++ptr;
		*ptr = 'O';
		game->nb_moves += 1;
		ft_putnbr_fd(game->nb_moves, 1);
		ft_putchar_fd('\n', 1);
	}
	mlx_delete_image(game->mlx.mlx, game->player);
	texture_load(game, &game->player, "./img/link_up.png");
}

void	move_right(t_game *game)
{
	char	*ptr;

	ptr = ft_strchr(game->map, 'P');
	if (*++ptr != '1' && *ptr != 'E')
	{
		*--ptr = '0';
		*++ptr = 'P';
		game->nb_moves += 1;
		ft_putnbr_fd(game->nb_moves, 1);
		ft_putchar_fd('\n', 1);
	}
	mlx_delete_image(game->mlx.mlx, game->player);
	texture_load(game, &game->player, "./img/link_right.png");
}

void	move_left(t_game *game)
{
	char	*ptr;

	ptr = ft_strchr(game->map, 'P');
	if (*--ptr != '1' && *ptr != 'E')
	{
		*++ptr = '0';
		*--ptr = 'P';
		game->nb_moves += 1;
		ft_putnbr_fd(game->nb_moves, 1);
		ft_putchar_fd('\n', 1);
	}
	mlx_delete_image(game->mlx.mlx, game->player);
	texture_load(game, &game->player, "./img/link_left.png");
}
