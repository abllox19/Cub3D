/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:12:40 by asoumare          #+#    #+#             */
/*   Updated: 2025/04/08 17:30:35 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	make_air(t_stock *slack, void *win_ptr)
{
	draw_image(slack, win_ptr, slack->img_air, '0');
}

void	make_wall(t_stock *slack, void *win_ptr)
{
	draw_image(slack, win_ptr, slack->img_wall, '1');
}

void	make_coin(t_stock *slack, void *win_ptr)
{
	draw_image(slack, win_ptr, slack->img_coin, 'C');
}

void	make_pnj(t_stock *slack, void *win_ptr)
{
	draw_image(slack, win_ptr, slack->img_pnj, 'P');
}

void	make_exit(t_stock *slack, void *win_ptr)
{
	draw_image(slack, win_ptr, slack->img_exit, 'E');
}
