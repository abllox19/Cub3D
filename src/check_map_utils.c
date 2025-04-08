/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:12:27 by asoumare          #+#    #+#             */
/*   Updated: 2024/06/20 18:45:16 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_wall_line(char *line, int num)
{
	int	i;

	i = 1;
	while (line[i])
	{
		if (line[i - 1] != num)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall_col(char *line, int num)
{
	int	i;
	int	len;

	len = ft_strlen(line) - 2;
	i = 0;
	if (line[0] != num || line[len] != num)
		return (0);
	return (1);
}

int	check_air_map(char *line, int check)
{
	int	len;

	len = ft_strlen(line);
	if (len != check)
		return (0);
	return (1);
}

int	cont_line(int fd)
{
	int		len;
	char	*line;

	len = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		len++;
	}
	return (len);
}

char	**test_map(int len, int fd)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	i = 0;
	map = (char **)malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			while (j < i)
				free(map[j++]);
			free(map);
			close(fd);
			exit(1);
		}
		i++;
	}
	return (map);
}
