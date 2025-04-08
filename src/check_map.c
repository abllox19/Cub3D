/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:38:22 by asoumare          #+#    #+#             */
/*   Updated: 2025/04/08 18:35:02 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_map_sup(char **map, int len)
{
	int	i;

	if (!check_wall_line(map[0], '1') || !check_wall_line(map[len - 1], '1'))
	{
		free_map(map);
		return (0);
	}
	i = 0;
	while (i < len)
	{
		if (!check_wall_col(map[i], '1') || !check_air_map(map[i],
				ft_strlen(map[0])))
		{
			free_map(map);
			return (0);
		}
		i++;
	}
	return (1);
}

void	place_joueur(char **map, int len)
{
	int		a;
	int		b;

	a = 0;
	while (a < len)
	{
		b = 0;
		while (map[a][b])
		{
			if (map[a][b] == 'N' || map[a][b] == 'S' || map[a][b] == 'W' || map[a][b] == 'E')
				map[a][b] = 'P';
			b++;
		}
		a++;
	}
	return ;
}

int	check_map(char *av)
{
	char	**map;
	int		len;

	map = init_map(av);
	if (!map)
		return (0);
	len = ft_count_words(map);
	if (check_lettre(map, len, "NSEW") != 1)
		return (printf("pas de position de joueur !"));
	if (!check_lettre_plus(map, len))
		return (printf("caractere inconnu !"));
	// if (!check_map_sup(map, len))			//si il y a des problem avec la map reactive ses deux ligne et fait une map carre.
	// 	return (0);
	place_joueur(map, len);
	check_dir(map, col_cmp(map, 'P'), line_cmp(map, 'P'));
	if (find_obj(map, ' '))
		return (printf("il y a un trou dans la maps !"));
	for (int i = 0; i < len; i++)
		printf("%s", map[i]);
	free_map(map);
	printf("%s", av);
	return (1);
}
