/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:11:07 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/23 11:11:40 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

void fill_cells(t_game *game, int y, int x)//row , col
{
	int		i;//pixel index along Col width
	int		j;//pixel index along Row height
	unsigned int	color;
	int 		pixel_index;
	int		pixel_x;
	int		pixel_y;
	unsigned int	*pixel_ptr;
	
	if (game->map[y][x] - '0' == 1)
		color = WHITE;
	else
		color = BLACK;
	j = 0;
	while (j < PIX) //each 100 pix height in Row
	{
		pixel_y = y * PIX + j;
		i = 0;
		while (i < PIX)// each 100 pix in col width
		{
			pixel_x = x * PIX + i;
			pixel_index = (pixel_y * game->size_line) + \
				(pixel_x * (game->bpp / 8));
			if (game->bpp == 32)
			{
				pixel_ptr = (unsigned int *)(game->data + pixel_index);
				*pixel_ptr = color;
			}		
			i++;
		}
		j++;
	}
}

void fill_gridlines(t_game *game)
{
	int		x;
	int		y;
	int 	pixel_index;
	int		pixel_y;
	int		pixel_v;
	int		pixel_h;
	unsigned int	*pixel_ptr;

	y = 0;
	while (y < game->dim.y)
	{
		pixel_y = y * PIX;
		x = 0;
		while (x < game->dim.x * PIX)
		{
			pixel_v = x * PIX;//vertical gridline (I understood, but sure to forget)
			pixel_h = x; //horizontal gridline
			if (game->bpp == 32)
			{
				pixel_index = (pixel_y * game->size_line) + \
					(pixel_v * (game->bpp / 8));
				pixel_ptr = (unsigned int *)(game->data + pixel_index);
				*pixel_ptr = BLUE;
				pixel_index = (pixel_y * game->size_line) + \
					(pixel_h * (game->bpp / 8));
				pixel_ptr = (unsigned int *)(game->data + pixel_index);
				*pixel_ptr = BLUE;
			}
			x++;
		}
		y++;
	}

}

void	player_pos(t_game *game)
{
	int				i;
	int				j;
	int				x;
	int				y;
	int 			pixel_index;
	int				pixel_x;
	int				pixel_y;
	unsigned int	*pixel_ptr;
	
	x = (game->pp.x * PIX) + (PIX / 2) - 5;
	y = (game->pp.y * PIX) + (PIX / 2) - 5;
	
	j = 0;
	while (j < 10) //each 10 pix height in Row
	{
		pixel_y = y + j;
		i = 0;
		while (i < 10)// each 10 pix in col width
		{
			pixel_x = x + i;
			pixel_index = (pixel_y * game->size_line) + \
				(pixel_x * (game->bpp / 8));
			if (game->bpp == 32)
			{
				pixel_ptr = (unsigned int *)(game->data + pixel_index);
				*pixel_ptr = YELLOW;
			}		
			i++;
		}
		j++;
	}
}

void	create_img(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->dim.y) // each row
	{
		x = 0;
		while (x < game->dim.x)//each col
		{
			fill_cells(game, y, x);
			x++;
		}
		y++;
	}
	fill_gridlines(game);
	player_pos(game);
}
