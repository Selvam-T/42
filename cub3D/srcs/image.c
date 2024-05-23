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


void set_pixel_color(t_game *game, int x, int y)
{
	int		i;
	int		j;
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
	while (j < PIX)
	{
		i = 0;
		while (i < PIX)
		{
			pixel_x = x * PIX + i;
			pixel_y = y * PIX + j;
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

void	create_img(t_game *game)
{
	int		x;
	int		y;
	int 		pixel_index;
	int		pixel_x;
	int		pixel_y;
	unsigned int	*pixel_ptr;

	y = 0;
	while (y < game->dim.y) // each row
	{
		x = 0;
		while (x < game->dim.x)//each col
		{
			set_pixel_color(game, x, y);
			x++;
		}
		y++;
	}
	
	//horizontal lines
	y = 1;
	while (y < game->dim.y)
	{
		x = 0;
		while (x < game->dim.x)
		{
			pixel_x = x * PIX;
			pixel_y = y * PIX;
			pixel_index = (pixel_y * game->size_line) + \
				(pixel_x * (game->bpp / 8));
			if (game->bpp == 32)
			{
				pixel_ptr = (unsigned int *)(game->data + pixel_index);
				*pixel_ptr = BLUE;
			}		
			x++;
		}
		y++;
	}
}
