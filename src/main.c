/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:47:24 by asoumare          #+#    #+#             */
/*   Updated: 2025/01/10 23:15:54 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_slack(t_stock **slack, char *av)
{
	*slack = (t_stock *)malloc(sizeof(t_stock));
	if (!*slack)
		return (0);
	(*slack)->height = ordonnee(av);
	(*slack)->width = abscisses(av);
	(*slack)->map = init_map(av);
	(*slack)->step = 1;
	(*slack)->j_x = find_pnj((*slack)->map, 'x');
	(*slack)->j_y = find_pnj((*slack)->map, 'y');
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 2)
		return (0);
	while (av[1][i])
		i++;
	i -= 4;
	if (av[1][i] == '.' && av[1][i +1] == 'b' &&
			av[1][i +2] == 'e' && av[1][i +3] == 'r')
		sup_main(av[1]);
	else
		write(2, "error ficher non compatible\n", 27);
	return (0);
}

int	sup_main(char *av)
{
	t_stock	*slack;

	slack = NULL;
	if (!check_map(av))
	{
		write(2, "Error\n", 6);
		quit(slack);
	}
	if (!init_slack(&slack, av))
		return (1);
	slack->mlx_ptr = mlx_init();
	if (!slack->mlx_ptr)
		return (1);
	slack->win_ptr = mlx_new_window(slack->mlx_ptr,
			slack->width, slack->height, "Mon jeu");
	if (!slack->win_ptr)
		return (1);
	load_images(slack);
	actu_map(slack, slack->win_ptr);
	mlx_hook(slack->win_ptr, 17, 0, close_window, slack);
	mlx_hook(slack->win_ptr, 2, 1, key_press, slack);
	mlx_loop(slack->mlx_ptr);
	quit(slack);
	printf("%s", av);
	return (0);
}
