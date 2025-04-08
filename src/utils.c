/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:55:52 by asoumare          #+#    #+#             */
/*   Updated: 2025/04/02 14:38:42 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

size_t	ft_count_words(char **map)
{
	size_t	count;

	count = 0;
	while (*map != NULL)
	{
		count++;
		map++;
	}
	return (count);
}

int	col_cmp(char **map, int obj)
{
	int	a;
	int	b;

	a = 0;
	while (map[a])
	{
		b = 0;
		while (map[a][b])
		{
			if (map[a][b] == obj)
				return (a);
			b++;
		}
		a++;
	}
	return (0);
}

int	line_cmp(char **map, int obj)
{
	int	a;
	int	b;

	a = 0;
	while (map[a])
	{
		b = 0;
		while (map[a][b])
		{
			if (map[a][b] == obj)
				return (b);
			b++;
		}
		a++;
	}
	return (0);
}

// int	abscisses(char *av)
// {
// 	char	**map;
// 	size_t	i;

// 	map = init_map(av);
// 	i = ft_strlen(map[1]) - 1;
// 	free_map(map);
// 	return (i * 32);
// }

// int	ordonnee(char *av)
// {
// 	char	**map;
// 	int		i;

// 	map = init_map(av);
// 	i = ft_count_words(map);
// 	free_map(map);
// 	return (i * 32);
// }
