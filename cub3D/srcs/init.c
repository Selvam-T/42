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

void	*init_graphics(t_game *game, char *str)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return(NULL);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->dim.x, game->dim.y, str);
	if (!game->win_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
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
		
	game->dim.x = 8;
	game->dim.y = 8;
	game->pp.x = 5;
	game->pp.y = 5;

	game->map = malloc(game->dim.y * sizeof(char *));
	if (game->map == NULL)
		return (error_handle1(game));
	game->map[0] = "11111111";
	game->map[1] = "10000001";
	game->map[2] = "10000001";
	game->map[3] = "10110001";
	game->map[4] = "10000001";
	game->map[5] = "10000N01";
	game->map[6] = "10000001";
	game->map[7] = "11111111";
	return (game);
}
