/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:36:56 by asoumare          #+#    #+#             */
/*   Updated: 2025/04/08 17:30:46 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	find_pnj(char **map, char c)
{
	int	a;
	int	b;

	a = 0;
	while (map[a])
	{
		b = 0;
		while (map[a][b])
		{
			if (map[a][b] == 'P')
			{
				if (c == 'x')
					return (a);
				else
					return (b);
			}
			b++;
		}
		a++;
	}
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_stock	*slack;

	slack = (t_stock *)param;
	if (keycode == 'w')
		mouv(slack, 'w');
	if (keycode == 's')
		mouv(slack, 's');
	if (keycode == 'a')
		mouv(slack, 'a');
	if (keycode == 'd')
		mouv(slack, 'd');
	if (keycode == 65307)
		close_window(slack);
	actu_map(slack, slack->win_ptr);
	return (0);
}

void	free_images(t_stock *slack)
{
	if (slack->img_air)
	{
		mlx_destroy_image(slack->mlx_ptr, slack->img_air);
		slack->img_air = NULL;
	}
	if (slack->img_wall)
	{
		mlx_destroy_image(slack->mlx_ptr, slack->img_wall);
		slack->img_wall = NULL;
	}
	if (slack->img_coin)
	{
		mlx_destroy_image(slack->mlx_ptr, slack->img_coin);
		slack->img_coin = NULL;
	}
	if (slack->img_pnj)
	{
		mlx_destroy_image(slack->mlx_ptr, slack->img_pnj);
		slack->img_pnj = NULL;
	}
	if (slack->img_exit)
	{
		mlx_destroy_image(slack->mlx_ptr, slack->img_exit);
		slack->img_exit = NULL;
	}
}

void	quit(t_stock *slack)
{
	printf("Quit : étape %d\n", slack->step);
	if (slack)
	{
		if (slack->map)
		{
			free_map(slack->map);
			slack->map = NULL;
		}
		free_images(slack);
		if (slack->mlx_ptr && slack->win_ptr)
		{
			mlx_destroy_window(slack->mlx_ptr, slack->win_ptr);
			slack->win_ptr = NULL;
		}
		if (slack->mlx_ptr)
		{
			mlx_destroy_display(slack->mlx_ptr);
			free(slack->mlx_ptr);
			slack->mlx_ptr = NULL;
		}
		free(slack);
		slack = NULL;
	}	
}

int	close_window(t_stock *slack)
{
	quit(slack);
	exit(1);
	return (0);
}
