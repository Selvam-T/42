/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:52:10 by sthiagar          #+#    #+#             */
/*   Updated: 2023/11/18 18:04:12 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_game *game, int w, int h, char *str)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		error_exit(-1, "Connection failed", game, 1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, w, h, str);
	if (!game->win_ptr)
		error_exit(-1, "Failed to create Window", game, 1);
	game->moves = 0;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		error_exit(0, "No input file", NULL, 0);
	else
	{
		get_map(argv[1], &game);
		init_game(&game, game.m_cols * PIX, game.m_rows * PIX, "so_long");
		init_images(&game);
		fill_canvas(&game);
		mlx_key_hook(game.win_ptr, key_hook, &game);
		mlx_hook(game.win_ptr, 17, 0, &exit_game, &game);
		mlx_loop(game.mlx_ptr);
	}
	return (0);
}
