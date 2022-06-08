/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:50:43 by fde-fede          #+#    #+#             */
/*   Updated: 2022/06/04 19:14:05 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

map_init(t_game game, char *argv)
{
	
}

int	main(int argc, char *argv[])
{
	t_game	game;

	check_arg(argc, argv);
	map_init(&game, argv[1]);
}
