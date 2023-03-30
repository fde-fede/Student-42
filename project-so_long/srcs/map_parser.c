/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:17:00 by fde-fede          #+#    #+#             */
/*   Updated: 2023/03/30 17:06:45 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int parse_map(char *argv, t_game *game)
{
	int	i;

	while (get_next_line(argv))
		game->data->map = get_next_line(argv);
	
// lectura mapa, guardado de datos y comprobar camino valido
} 