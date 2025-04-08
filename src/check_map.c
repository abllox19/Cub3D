/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:10:22 by asoumare          #+#    #+#             */
/*   Updated: 2025/04/02 14:39:29 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

// void	free_map(char **map)
// {
// 	int	i;

// 	if (!map)
// 		return ;
// 	i = 0;
// 	while (map[i])
// 	{
// 		free(map[i]);
// 		i++;
// 	}
// 	free(map);
// }

// int	check_map_sup(char **map, int len)
// {
// 	int	i;

// 	if (!check_wall_line(map[0], '1') || !check_wall_line(map[len - 1], '1'))
// 	{
// 		free_map(map);
// 		return (0);
// 	}
// 	i = 0;
// 	while (i < len)
// 	{
// 		if (!check_wall_col(map[i], '1') || !check_air_map(map[i],
// 				ft_strlen(map[0])))
// 		{
// 			free_map(map);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

char	**init_map(char *av)
{
	int		len;
	int		fd;
	char	**map;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit(1);
	len = cont_line(fd);
	close(fd);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit(1);
	map = test_map(len, fd);
	if (!map)
	{
		close(fd);
		exit(1);
	}
	map[len] = NULL;
	close(fd);
	return (map);
}

int	check_map(char *av)
{
	char	**map;
	int		len = 0;

	map = init_map(av);
	if (!map)
		return (0);
	len = ft_count_words(map);
	if (!check_lettre(map, len, 'C') || check_lettre(map, len, 'E') != 1
		|| check_lettre(map, len, 'P') != 1)
		return (0);
	// if (!check_lettre_plus(map, len))
	// 	return (0);
	// if (!check_map_sup(map, len))
	// 	return (0);
	// check_dir(map, col_cmp(map, 'P'), line_cmp(map, 'P'));
	// if (!find_obj(map, 'E') || check_lettre(map, len, 'C'))
	// 	return (0);
	// free_map(map);
    len = 0;
    while (map[len])
	    printf("%s", map[len++]);
	return (1);
}
