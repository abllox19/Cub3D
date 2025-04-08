/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:37:26 by asoumare          #+#    #+#             */
/*   Updated: 2024/06/17 20:16:58 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_image(t_stock *slack, void *win_ptr, void *img, char target)
{
	t_int	nb;

	nb.img_width = 32;
	nb.img_height = 32;
	nb.y = 0;
	nb.a = 0;
	while (slack->map[nb.a])
	{
		nb.x = 0;
		nb.b = 0;
		while (slack->map[nb.a][nb.b])
		{
			if (slack->map[nb.a][nb.b] == target)
				mlx_put_image_to_window(slack->mlx_ptr,
					win_ptr, img, nb.x, nb.y);
			nb.x += nb.img_width;
			nb.b++;
		}
		nb.y += nb.img_height;
		nb.a++;
	}
}

void	load_images(t_stock *slack)
{
	t_int	nb;

	slack->img_air = mlx_xpm_file_to_image(slack->mlx_ptr,
			"img/sol.xpm", &nb.img_width, &nb.img_height);
	if (!slack->img_air)
		free_images(slack);
	slack->img_wall = mlx_xpm_file_to_image(slack->mlx_ptr,
			"img/wall.xpm", &nb.img_width, &nb.img_height);
	if (!slack->img_wall)
		free_images(slack);
	slack->img_coin = mlx_xpm_file_to_image(slack->mlx_ptr,
			"img/coin.xpm", &nb.img_width, &nb.img_height);
	if (!slack->img_coin)
		free_images(slack);
	slack->img_pnj = mlx_xpm_file_to_image(slack->mlx_ptr,
			"img/pnj.xpm", &nb.img_width, &nb.img_height);
	if (!slack->img_pnj)
		free_images(slack);
	slack->img_exit = mlx_xpm_file_to_image(slack->mlx_ptr,
			"img/door.xpm", &nb.img_width, &nb.img_height);
	if (!slack->img_exit)
		free_images(slack);
	check_imgs(slack);
	return ;
}

void	check_imgs(t_stock *slack)
{
	if ((!slack->img_coin || !slack->img_air || !slack->img_exit
			|| !slack->img_pnj || !slack->img_wall))
		close_window(slack);
}
