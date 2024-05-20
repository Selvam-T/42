/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:51:09 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/20 15:51:40 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

void	*error_handle1(t_game *game)//free map
{
	free1(game);
	return (NULL);
}

void	*error_handle2(t_game *game)//ideally free mlx->ptr, win->ptr, map and game
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free1(game);
	return (NULL);
}
