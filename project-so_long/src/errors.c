/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:36:54 by fde-fede          #+#    #+#             */
/*   Updated: 2022/06/08 17:45:37 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	problems(char *problem, char *whole_chars)
{
	ft_putendl_fd(problem, 2);
	free(whole_chars);
	exit (0);
}

void	check_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
		{
			ft_putendl_fd("map is not surrounded by walls", 2);
			free(line);
			exit (1);
		}
		i++;
	}
}

void	checl_map_elements(char	*whole_chars)
{
	int	i;
	int	count_p;

	i = 0;
	count_p = 0;
	while (whole_chars[i] != '\0')
	{
		if (whole_chars[i] == 'P')
			count_p++;
		if ((whole_chars[i] != '1') && (whole_chars[i] != '0')
			&& (whole_chars[i] != 'E') && (whole_chars[i] != 'P')
			&& (whole_chars[i] != 'C'))
		{
			ft_putendl_fd("Error\nFile contains not allowed characters", 2);
			free(whole_chars);
			exit (1);
		}
		i++;
	}
	if (count_p > 1)
		problems("only one player should be on the map", whole_chars);
}

void	check_arg(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putendl_fd("Error\nInvalid number of arguments", 2);
		exit (0);
	}
	if ((ft_strlen(argv[1]) < 4) || (!ft_strrchr(argv[1], '.')))
	{
		ft_putendl_fd("Error\nInvalid argument", 2);
		exit (0);
	}
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
	{
		ft_putendl_fd("Error\nfile must be of type \"<name>.ber\"", 2);
		exit (0);
	}
}
