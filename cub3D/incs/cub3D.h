/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:02:15 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/20 14:45:33 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define PIX 100

typedef struct s_xy
{
	int	x;
	int	y;
} t_xy;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_xy	dim;
	t_xy	pp;
	t_xy	dv;
	char	**map;
} t_game;

//error_handle.c
void	*error_handle1(t_game *game);
//free.c
void	free1(t_game *game);
//map.c
int	grid_value(char **map, int r, int c);
//init.c
void	*init_graphics(t_game *game, char *str);
t_game	*init_game();
//test.c
void	print_game(t_game *game);

#endif
