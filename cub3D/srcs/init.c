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

void	init_dv(t_game *game, char c)
{
//N = (0, -1); S = (0, 1); E = (1, 0); W = (-1, 0) --> player looking direction
	if (c == 'N' || c == 'S')
	{
		game->dv.x = 0;
		game->dv.y = -1;
		if (c == 'S')
			game->dv.y = 1;
	}
	if (c == 'E' || c == 'W')
	{
		game->dv.y = 0;
		game->dv.x = 1;
		if (c == 'W')
			game->dv.x = -1;
	}
}

void	init_cp(t_game *game)
{
	//initialize camera plane perpendicular to the direction
	(void)game;
}

t_game	*init_game()
{
	t_game	*game;

	game = malloc(sizeof(t_game) * 1);
	if (game == NULL)
		return (NULL);
	game->dim.y = 10;//row
	game->dim.x = 8;//col
	game->pp.x = 5;
	game->pp.y = 5;

	init_dv(game, 'N');
	game->cp.x = 0.66;//this varies in relation to dv?
	game->cp.y = 0;//this varies in relatin to dv?
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
	game->map[7] = "10010001";
	game->map[8] = "10010001";
	game->map[9] = "11111111";
	
	if (init_graphics(game, "Cube3D") == NULL)
		return (NULL);
	if (init_img(game) == -1)
		return (NULL);
	return (game);
}
