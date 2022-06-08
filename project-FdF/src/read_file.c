/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:06:08 by fde-fede          #+#    #+#             */
/*   Updated: 2022/05/26 21:47:32 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*ft_mapstr_to_map(t_map *map, char **strmap)
{
	int		index_x;
	int		index_y;
	char	**tmp;

	index_y = 0;
	while (index_y != map->size_y)
	{
		tmp = ft_split(strmap[index_y], ' ');
		if (!tmp)
			return (NULL);
		map->map[index_y] = (t_vector *)ft_calloc(map->size_x,
				sizeof(t_vector));
		if (!map->map[index_y] || !tmp)
			return ((t_map *)free_strmap(tmp));
		index_x = 0;
		while (index_x != map->size_x)
		{
			map->map[index_y][index_x] = create_vector(index_x, index_y,
					ft_atoi(tmp[index_x]));
			index_x++;
		}
		free_strmap(tmp);
		index_y++;
	}
	return (map);
}

t_map	*ft_set_size_map(t_map *map, char **strmap)
{
	char	**tmp;
	int		index;

	while (strmap[map->size_y] != NULL)
		map->size_y++;
	tmp = ft_split(strmap[0], ' ');
	if (!tmp)
	{
		free_strmap(strmap);
		return (NULL);
	}
	while (tmp[map->size_x] != NULL)
		map->size_x++;
	index = 0;
	while (tmp[index] != NULL)
	{
		free(tmp[index]);
		index++;
	}
	free(tmp[index]);
	free(tmp);
	return (map);
}

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
	char	*tmp;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	tmp = ft_strtrim(line, " \n");
	strmap = NULL;
	if (tmp != NULL)
	{
		strmap = ft_join_line_to_map(strmap, tmp);
		while (line != NULL)
		{
			line = get_next_line(fd);
			if (line == NULL)
				break ;
			tmp = ft_strtrim(line, " \n");
			if (!tmp)
				return ((char **)(free_strmap(strmap)));
			free(line);
			strmap = ft_join_line_to_map(strmap, tmp);
		}
	}
	return (strmap);
}

t_map	*read_file(const char *file)
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
	map->map = (t_vector **)ft_calloc(map->size_y, sizeof(t_vector *));
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
