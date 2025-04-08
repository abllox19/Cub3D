/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 20:57:00 by asoumare          #+#    #+#             */
/*   Updated: 2024/06/07 20:17:40 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mouv(t_stock *slack, char c)
{
	int	new_a;
	int	new_b;

	new_a = slack->j_x;
	new_b = slack->j_y;
	if (c == 'w')
		new_a--;
	else if (c == 's')
		new_a++;
	else if (c == 'a')
		new_b--;
	else if (c == 'd')
		new_b++;
	if (slack->map[new_a][new_b] == 'E')
		if (!check_lettre(slack->map, slack->height / 32, 'C'))
			close_window(slack);
	if (slack->map[new_a][new_b] != '1' && slack->map[new_a][new_b] != 'E')
	{
		slack->map[slack->j_x][slack->j_y] = '0';
		slack->map[new_a][new_b] = 'P';
		slack->j_x = new_a;
		slack->j_y = new_b;
		printf("nombre de pas :%d\n", slack->step++);
	}
}
