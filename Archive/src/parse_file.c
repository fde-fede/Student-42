/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestrada <jestrada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:51:42 by jestrada          #+#    #+#             */
/*   Updated: 2022/05/19 19:11:11 by jestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_join_line_to_map(char **strmap, char *line)
{
	char	**new_strmap;
	int		size;
	int		index;

	size = 0;
	if (strmap != NULL)
	{
		while (strmap[size] != NULL)
			size++;
	}
	new_strmap = (char **)ft_calloc(size + 2, sizeof(char *));
	if (!new_strmap)
		return (NULL);
	index = 0;
	while (size != index)
	{
		new_strmap[index] = strmap[index];
		index++;
	}
	free(strmap);
	new_strmap[index] = line;
	new_strmap[index + 1] = NULL;
	return (new_strmap);
}

char	**ft_get_map(const char *map)
{
	int		fd;
	char	*line;
	char	**strmap;
	char	*temp;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	temp = ft_strtrim(line, " \n");
	strmap = NULL;
	if (temp != NULL)
	{
		strmap = ft_join_line_to_map(strmap, temp);
		while (line != NULL)
		{
			line = get_next_line(fd);
			if (line == NULL)
				break ;
			temp = ft_strtrim(line, " \n");
			if (!temp)
				return ((char **)(free_strmap(strmap)));
			free(line);
			strmap = ft_join_line_to_map(strmap, temp);
		}
	}
	return (strmap);
}

t_map	*ft_mapstr_to_map(t_map *map, char **strmap)
{
	int		index_y;
	int		index_x;
	char	**temp;

	index_y = 0;
	while (index_y != map->size_y)
	{
		temp = ft_split(strmap[index_y], ' ');
		if (!temp)
			return (NULL);
		map->map[index_y] = (t_vec *)ft_calloc(map->size_x, sizeof(t_vec));
		if (!map->map[index_y] || !temp)
			return ((t_map *)free_strmap(temp));
		index_x = 0;
		while (index_x != map->size_x)
		{
			map->map[index_y][index_x] = create_vector(index_x, index_y,
					ft_atoi(temp[index_x]));
			index_x++;
		}
		free_strmap(temp);
		index_y++;
	}
	return (map);
}

t_map	*ft_set_size_map(t_map *map, char **strmap)
{
	char	**temp;
	int		index;

	while (strmap[map->size_y] != NULL)
		map->size_y++;
	temp = ft_split(strmap[0], ' ');
	if (!temp)
	{
		free_strmap(strmap);
		return (NULL);
	}
	while (temp[map->size_x] != NULL)
		map->size_x++;
	index = 0;
	while (temp[index] != NULL)
	{
		free(temp[index]);
		index++;
	}
	free(temp[index]);
	free(temp);
	return (map);
}

t_map	*parse_file(const char *file)
{
	char	**strmap;
	t_map	*map;

	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (NULL);
	strmap = ft_get_map(file);
	if (!strmap)
		return (NULL);
	if (!ft_set_size_map(map, strmap))
		return (NULL);
	map->map = (t_vec **)ft_calloc(map->size_y, sizeof(t_vec *));
	if (!map->map)
	{
		free_strmap(strmap);
		return (NULL);
	}
	if (!ft_mapstr_to_map(map, strmap))
	{
		free_map(map);
		free_strmap(strmap);
		return (NULL);
	}
	free_strmap(strmap);
	return (map);
}
