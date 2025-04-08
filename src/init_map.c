/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:50:21 by asoumare          #+#    #+#             */
/*   Updated: 2025/04/08 17:30:50 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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
