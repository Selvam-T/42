/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:49:19 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/20 15:50:14 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	grid_value(char **map, int r, int c)
{
	return (map[r][c] - '0');
}

int	draw_sqr(t_game *game, int x, int y)
{
	int		i;
	int		j;
	unsigned int	color;
	
	if (game->map[x][y] - '0' == 1)
		color = 0xFFFFFF;
	else
		color = 0x000000;
	j = 0;
	while (j < PIX)
	{
		i = 0;
		while (i < PIX)
		{
			if (mlx_pixel_put(game->mlx, game->win, \
				(x * PIX) + i, (y * PIX) + j, color) == -1)
				return (-1);
			
			i++;
		}
		j++;
	}
	return (0);	
}

int	draw_canvas(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->dim.y)
	{
		x = 0;
		while (x < game->dim.x)
		{
			if (draw_sqr(game, x, y) == -1)
				return (-1);
			x++;
		}
		y++;
	}
	//horizontal lines ??
	y = 1;
	while (y < game->dim.y)
	{
		x = 0;
		while (x < PIX * game->dim.x)
		{
			mlx_pixel_put(game->mlx, game->win, x, y * PIX, 0x0000FF);
			x++;
		}
		y++;
	}
	
	//vertical lines ??
	x = 1;
	while (x < game->dim.x)
	{
		y = 0;
		while (y < PIX * game->dim.y)
		{
			mlx_pixel_put(game->mlx, game->win, x * PIX, y, 0x0000FF);
			y++;
		}
		x++;
	}
	
	return (0);
}

int	draw_player(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	loop;
	
	x = (game->pp.x * PIX) + (PIX / 2) - 5;
	y = (game->pp.y * PIX) + (PIX / 2) - 5;
	
	for (loop = 0; loop < 10; loop++)
	{
	
		j = 0;
		while (j < 10)
		{
			i = 0;
			while (i < 10)
			{
			mlx_pixel_put(game->mlx, game->win, x - 10 + i, y + j, 0x000000);
				if (mlx_pixel_put(game->mlx, game->win, \
					x + i, y + j, 0xFFFF00) == -1)
					return (-1);
				
				i++;
			}
			j++;
		}
	x += 10;
	sleep(1);
	}
	return (0);
}

void	create_2dmap()
{
	if (draw_canvas(game) == 1)
		return(free3(game));
	if (draw_player(game) == 1)
		return(free3(game));
}
/*

mlx_new_image.c
mlx_get_data_addr.c
mlx_put_image_to_window.c

free(img);
    return ((void *)0);

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
} t_game;*/
