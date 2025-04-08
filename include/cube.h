/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:54:43 by asoumare          #+#    #+#             */
/*   Updated: 2025/04/02 14:37:05 by asoumare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <stdbool.h>
# include <ctype.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>

/*          check           */

int	check_lettre(char **map, int len, char lettre);
int	check_map(char *av);
int	check_acces(char **map, int a, int b);
int	cont_line(int fd);
char	**test_map(int len, int fd);
int	find_obj(char **map, int obj);
void	check_dir(char **map, int a, int b);

/*          utils           */

size_t	ft_count_words(char **map);
int	check_lettre_plus(char **map, int len);
int	col_cmp(char **map, int obj);
int	line_cmp(char **map, int obj);
int	abscisses(char *av);
int	ordonnee(char *av);

#endif