/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actu_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:00:24 by asoumare          #+#    #+#             */
/*   Updated: 2024/06/07 20:32:18 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	actu_map(t_stock *slak, void *win_ptr)
{
	make_air(slak, win_ptr);
	make_wall(slak, win_ptr);
	make_coin(slak, win_ptr);
	make_pnj(slak, win_ptr);
	make_exit(slak, win_ptr);
}
