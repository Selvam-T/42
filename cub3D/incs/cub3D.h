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
# include <math.h>

# define PIX 100
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define BLUE 0x00FFFF

typedef struct s_xy
{
	double	y;//row , HEIGHT
	double	x;//column, WIDTH
} t_xy;

typedef struct s_game
{
	char	**map;
	t_xy	dim;
	t_xy	pp;//position of the player
	t_xy	dv;//direction of player
	t_xy	cp;//camera plane ?? not sure if represented as x,y
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int	bpp;
	int	size_line;
	int	endian;
} t_game;

//free.c
void	*free1(t_game *game);
int	free2(t_game *game);
int	free3(t_game *game);
int	exit_game(t_game *game);
//init.c
void	*init_graphics(t_game *game, char *str);
t_game	*init_game();
//test.c
void	print_game(t_game *game);
//image.c
void	create_img(t_game *game);
#endif
