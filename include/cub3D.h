/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:07:02 by asoumare          #+#    #+#             */
/*   Updated: 2025/04/08 17:48:07 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

/*      test        */

typedef struct s_int
{
	int		x;
	int		y;
	int		a;
	int		b;
	int		img_width;
	int		img_height;
}			t_int;

typedef struct s_stock
{
	int		width;
	int		height;
	int		step;
	void	*img_air;
	void	*img_wall;
	void	*img_coin;
	void	*img_exit;
	void	*img_pnj;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	**map;
	int		j_x;
	int		j_y;
}			t_stock;

/*      check map       */

int		check_map(char *av);
int		find_pnj(char **map, char c);
int		check_lettre_plus(char **map, int len);
void	quit(t_stock *slack);
int		close_window(t_stock *slack);
void	check_imgs(t_stock *slack);

/*      check map utils       */

int		check_wall_line(char *line, int num);
int		check_wall_col(char *line, int num);
int		check_air_map(char *line, int check);
char	**test_map(int len, int fd);
char	**init_map(char *av);
int		cont_line(int fd);

/*      check obj           */

void	check_dir(char **map, int x, int c);
int		find_obj(char **map, int obj);
int		check_lettre(char **map, int len, char *lettre);
void	free_map(char **map);

/*      make map            */

void	draw_image(t_stock *slack, void *win_ptr, void *img, char target);
void	make_air(t_stock *slak, void *win_ptr);
void	make_wall(t_stock *slak, void *win_ptr);
void	make_pnj(t_stock *slak, void *win_ptr);
void	make_exit(t_stock *slak, void *win_ptr);
void	load_images(t_stock *slack);

/*      actu map			*/

void	actu_map(t_stock *slak, void *win_ptr);

/*		key					*/

int		key_press(int keycode, void *param);
void	mouv(t_stock *slack, char c);

/*      utils       		*/

int		sup_main(char *av);
size_t	ft_count_words(char **words);
int		col_cmp(char **map, int obj);
int		line_cmp(char **map, int obj);
int		ordonnee(char *av);
int		abscisses(char *av);
void	make_coin(t_stock *slack, void *win_ptr);
void	free_images(t_stock *slack);
int		ft_strlen(const char *str);
char	*get_next_line(int fd);

#endif