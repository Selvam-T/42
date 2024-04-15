/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:37:16 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/09 13:39:19 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_pic(t_game *game, char c)
{
	if (c == '1')
		return (game->image.wall);
	else if (c == '0')
		return (game->image.blank);
	else if (c == 'C')
		return (game->image.cltbl);
	else if (c == 'P')
		return (game->image.player);
	else if (c == 'E')
		return (game->image.exit);
	return (NULL);
}

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->image.wall);
	mlx_destroy_image(game->mlx_ptr, game->image.player);
	mlx_destroy_image(game->mlx_ptr, game->image.exit);
	mlx_destroy_image(game->mlx_ptr, game->image.blank);
	mlx_destroy_image(game->mlx_ptr, game->image.cltbl);
}

void	init_images(t_game *game)
{
	game->image.h = PIX;
	game->image.w = PIX;
	game->image.wall = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./image/fence.xpm", &game->image.w, &game->image.h);
	game->image.player = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./image/monkey.xpm", &game->image.w, &game->image.h);
	game->image.exit = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./image/hut.xpm", &game->image.w, &game->image.h);
	game->image.blank = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./image/blank.xpm", &game->image.w, &game->image.h);
	game->image.cltbl = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./image/banana.xpm", &game->image.w, &game->image.h);
}

void	fill_canvas(t_game *game)
{
	int		i;
	int		j;
	int		row;
	int		col;
	void	*pic;

	i = 0;
	pic = NULL;
	while (i < game->m_rows)
	{
		row = i * PIX;
		j = 0;
		while (j < game->m_cols)
		{
			col = j * PIX;
			pic = get_pic(game, game->map[i][j].c);
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				pic, col, row);
			j++;
		}
		i++;
	}
}
