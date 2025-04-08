/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:58:39 by asoumare          #+#    #+#             */
/*   Updated: 2024/06/10 17:44:04 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_lettre(char **map, int len, char lettre)
{
	int		a;
	int		b;
	int		cont;
	char	c;

	cont = 0;
	a = 0;
	b = 0;
	while (a < len)
	{
		b = 0;
		while (map[a][b])
		{
			c = map[a][b];
			if (c == lettre)
				cont += 1;
			b++;
		}
		a++;
	}
	return (cont);
}

int	check_lettre_plus(char **map, int len)
{
	int		a;
	int		b;
	char	c;

	a = 0;
	while (a < len)
	{
		b = 0;
		while (map[a][b])
		{
			c = map[a][b];
			if (c != 'P' && c != '1' && c != 'C'
				&& c != 'E' && c != '0' && c != '\n')
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

int	check_acces(char **map, int a, int b)
{
	if (map[a + 1][b] == 'x')
		return (1);
	if (map[a - 1][b] == 'x')
		return (1);
	if (map[a][b + 1] == 'x')
		return (1);
	if (map[a][b - 1] == 'x')
		return (1);
	return (0);
}

int	find_obj(char **map, int obj)
{
	int	a;
	int	b;

	a = 0;
	while (map[a])
	{
		b = 0;
		while (map[a][b])
		{
			if (map[a][b] == obj && check_acces(map, a, b))
				return (1);
			b++;
		}
		a++;
	}
	return (0);
}

void	check_dir(char **map, int a, int b)
{
	map[a][b] = 'x';
	if (map[a + 1][b] == '0' || map[a +1][b] == 'C')
		check_dir(map, a + 1, b);
	if (map[a - 1][b] == '0' || map[a -1][b] == 'C')
		check_dir(map, a - 1, b);
	if (map[a][b + 1] == '0' || map[a][b +1] == 'C')
		check_dir(map, a, b + 1);
	if (map[a][b - 1] == '0' || map[a][b +1] == 'C')
		check_dir(map, a, b - 1);
}
