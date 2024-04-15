/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:55:14 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/09 17:53:28 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

# define PIX 100

typedef struct s_dim
{
	int	row;
	int	col;
}	t_dim;

typedef struct s_map
{
	char	c;
	int		v;
}	t_map;

typedef struct s_path
{
	int	found;
	int	cltbl;
}	t_path;

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*blank;
	void	*cltbl;
	int		h;
	int		w;
}	t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	image;
	t_map	**map;
	int		m_rows;
	int		m_cols;
	t_dim	start;
	t_dim	cur_pos;
	int		c_count;
	int		moves;
}	t_game;

int		exit_game(t_game *window);
void	error_exit(int fd, char *str, t_game *game, int p_err);
void	init_images(t_game *game);
void	free_images(t_game *game);
void	fill_canvas(t_game *game);
int		key_hook(int keycode, t_game *game);
void	free_map(t_map **map, int rows);
void	validate_map(t_game *game);
void	get_map_dimension(int fd, t_game *game);
void	get_map(char *mapfile, t_game *game);

#endif
