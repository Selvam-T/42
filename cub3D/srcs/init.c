/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:00:14 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/20 17:01:28 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	init_img(t_game *game)
{
	game->img = mlx_new_image(game->mlx, game->dim.x * PIX, game->dim.y * PIX);
	if (game->img == NULL)
		return (free3(game));
	game->data = mlx_get_data_addr(game->img, &game->bpp, \
		&game->size_line, &game->endian);
	return(0);
}

void	*init_graphics(t_game *game, char *str)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free2(game);
		return(NULL);
	}
	game->win = mlx_new_window(game->mlx, game->dim.x * PIX, game->dim.y * PIX, str);
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free2(game);
		return (NULL);
	}
	return (game);
}

t_game	*init_game()
{
	t_game	*game;

	game = malloc(sizeof(t_game) * 1);
	if (game == NULL)
		return (NULL);
	game->dim.y = 8;//row
	game->dim.x = 8;//col
	game->pp.x = 5;
	game->pp.y = 5;

	game->map = malloc(game->dim.y * sizeof(char *));
	if (game->map == NULL)
		return (free1(game));
	game->map[0] = "11111111";
	game->map[1] = "11100001";
	game->map[2] = "10000001";
	game->map[3] = "10110001";
	game->map[4] = "10000001";
	game->map[5] = "10000N01";
	game->map[6] = "10000001";
	game->map[7] = "11111111";
	
	if (init_graphics(game, "Cube3D") == NULL)
		return (NULL);
	if (init_img(game) == -1)
		return (NULL);
	return (game);
}
