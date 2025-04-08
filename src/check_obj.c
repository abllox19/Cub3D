/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:58:39 by asoumare          #+#    #+#             */
/*   Updated: 2025/04/08 18:57:15 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	check_lettre(char **map, int len, char *lettre)
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
			for (int i = 0; i < ft_strlen(lettre); i++)
			{	
				if (c == lettre[i])
				cont += 1;
			}
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
			if (c != '1' && c != 'C' && c != 'W' && c != 'S' && c != 'N' && c != ' '
				&& c != 'E' && c != '0' && c != '\n')
			{
				printf("%c", c);
				return (0); 
			}
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
	if (map[a + 1][b] == '0')
		check_dir(map, a + 1, b);
	if (map[a - 1][b] == '0')
		check_dir(map, a - 1, b);
	if (map[a][b + 1] == '0')
		check_dir(map, a, b + 1);
	if (map[a][b - 1] == '0')
		check_dir(map, a, b - 1);
}
