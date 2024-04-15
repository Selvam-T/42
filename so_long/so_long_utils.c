/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:03:29 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/09 13:36:21 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_moves(t_game *game)
{
	char	*str;
	int		len;

	game->moves += 1;
	str = ft_itoa(game->moves);
	len = ft_strlen(str);
	write(1, "Move: ", 6);
	write(1, str, len);
	write(1, "\n", 1);
	free(str);
}

static void	horizontal_move(t_game *game, int nextr)
{
	int	r;
	int	c;

	r = game->cur_pos.row;
	c = game->cur_pos.col;
	if (game->map[nextr][c].c != '1' && game->map[nextr][c].c != 'E')
	{
		if (game->map[nextr][c].c == 'C')
			game->c_count -= 1;
		game->map[r][c].c = '0';
		game->map[nextr][c].c = 'P';
		game->cur_pos.row = nextr;
		print_moves(game);
	}
	if (game->map[nextr][c].c == 'E' && game->c_count == 0)
	{
		print_moves(game);
		exit_game(game);
	}
}

static void	vertical_move(t_game *game, int nextc)
{
	int	r;
	int	c;

	r = game->cur_pos.row;
	c = game->cur_pos.col;
	if (game->map[r][nextc].c != '1' && game->map[r][nextc].c != 'E')
	{
		if (game->map[r][nextc].c == 'C')
			game->c_count -= 1;
		game->map[r][c].c = '0';
		game->map[r][nextc].c = 'P';
		game->cur_pos.col = nextc;
		print_moves(game);
	}
	if (game->map[r][nextc].c == 'E' && game->c_count == 0)
	{
		print_moves(game);
		exit_game(game);
	}
}

int	exit_game(t_game *game)
{
	if (game)
	{
		free_map(game->map, game->m_rows);
		free_images(game);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_game *game)
{
	int	r;
	int	c;

	r = game->cur_pos.row;
	c = game->cur_pos.col;
	if (keycode == 119 || keycode == 113 || keycode == 65362)
		horizontal_move(game, game->cur_pos.row - 1);
	else if (keycode == 115 || keycode == 122 || keycode == 65364)
		horizontal_move(game, game->cur_pos.row + 1);
	else if (keycode == 100 || keycode == 65363)
		vertical_move(game, game->cur_pos.col + 1);
	else if (keycode == 97 || keycode == 100 || keycode == 65361)
		vertical_move(game, game->cur_pos.col - 1);
	else if (keycode == 65307)
		exit_game(game);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	fill_canvas(game);
	return (0);
}
