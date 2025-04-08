/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:53:09 by asoumare          #+#    #+#             */
/*   Updated: 2025/04/02 14:21:42 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	run_prog(char *av)
{
	// t_stock	*slack;

	// slack = NULL;
	if (!check_map(av))
	{
		perror("Error de map\n");
		exit (1);
	}
	// if (!init_slack(&slack, av))
	// 	return (1);
	// slack->mlx_ptr = mlx_init();
	// if (!slack->mlx_ptr)
	// 	return (1);
	// slack->win_ptr = mlx_new_window(slack->mlx_ptr,
	// 		slack->width, slack->height, "Mon jeu");
	// if (!slack->win_ptr)
	// 	return (1);
	// load_images(slack);
	// actu_map(slack, slack->win_ptr);
	// mlx_hook(slack->win_ptr, 17, 0, close_window, slack);
	// mlx_hook(slack->win_ptr, 2, 1, key_press, slack);
	// mlx_loop(slack->mlx_ptr);
	// quit(slack);
	// printf("%s", av);
	return (0);
}

int main(int ac, char **av)
{
	int	i;

	i = 0;
    printf("\n\n");
	if (ac != 2)
		return (printf("EROOR : ./cub3D < nom d'un ficher .cub >\n"));
	while (av[1][i])
		i++;
	i -= 4;
	if (av[1][i] == '.' && av[1][i +1] == 'c' &&
			av[1][i +2] == 'u' && av[1][i +3] == 'b')
        {
            printf("la map est : %s\n", av[1]);
            run_prog(av[1]);
        }
	else
		printf("error ficher non compatible\n");
	return (0);
}