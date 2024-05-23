/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:52:14 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/20 15:52:26 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

void	*free1(t_game *game)
{
	if (game)
		free(game);
	game = NULL;
	return (NULL);
}

int	free2(t_game *game)
{
	free(game->map);
	game->map = NULL;
	free1(game);
	return (-1);
}

int	free3(t_game *game)
{
	if (game->img != NULL)
    	{
        	mlx_destroy_image(game->mlx, game->img);
        	game->img = NULL;
   	}
   	if (game->img != NULL)
    	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
    	}
    	if (game->mlx != NULL)
    	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	return (free2(game));
}

int	exit_game(t_game *game)
{
	(void)game;
	//if (game)
	//	free3(game);
	exit(EXIT_SUCCESS);
}
