/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actu_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:00:24 by asoumare          #+#    #+#             */
/*   Updated: 2025/04/08 17:31:20 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	actu_map(t_stock *slak, void *win_ptr)
{
	make_air(slak, win_ptr);
	make_wall(slak, win_ptr);
	make_coin(slak, win_ptr);
	make_pnj(slak, win_ptr);
	make_exit(slak, win_ptr);
}
