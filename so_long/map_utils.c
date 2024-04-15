/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:17:22 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/01 15:29:38 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

static t_path	valid_path(t_map **map, t_dim cur, t_path path)
{
	int	r;
	int	c;

	r = cur.row;
	c = cur.col;
	if ((map[r][c].c == '1') || (map[r][c].v == 1))
		return (path);
	if (map[r][c].c == 'E')
	{
		path.found += 1;
		return (path);
	}
	if (map[r][c].c == 'C')
		path.cltbl++;
	map[r][c].v = 1;
	path = valid_path(map, (t_dim){r, c - 1}, path);
	path = valid_path(map, (t_dim){r, c + 1}, path);
	path = valid_path(map, (t_dim){r + 1, c}, path);
	path = valid_path(map, (t_dim){r - 1, c}, path);
	return (path);
}

static void	count_mapped_characters(t_game *gme, int *p_count, int *e_count)
{
	int	i;
	int	j;

	i = 1;
	while (i < gme->m_rows)
	{
		j = 1;
		while (j < gme->m_cols)
		{
			if (gme->map[i][j].c == 'C')
				gme->c_count++;
			else if (gme->map[i][j].c == 'P')
			{
				gme->start.row = i;
				gme->start.col = j;
				(*p_count)++;
			}
			else if (gme->map[i][j].c == 'E')
				(*e_count)++;
			else if (!((gme->map[i][j].c == '0') || (gme->map[i][j].c == '1')))
				error_exit(-2, "Invalid map: invalid character", gme, 0);
			j++;
		}
		i++;
	}
}

static void	check_closedwall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->m_cols)
	{
		if ((game->map[0][i].c != '1') || \
			(game->map[game->m_rows - 1][i].c != '1'))
			error_exit(-2, "Invalid map: wall not closed", game, 0);
		i++;
	}
	i = 0;
	while (i < game->m_rows)
	{
		if ((game->map[i][0].c != '1') || \
			(game->map[i][game->m_cols - 1].c != '1'))
			error_exit(-2, "Invalid map: wall not closed", game, 0);
		i++;
	}
}

void	validate_map(t_game *game)
{
	int			p_count;
	int			e_count;
	t_path		path;

	game->c_count = 0;
	p_count = 0;
	e_count = 0;
	check_closedwall(game);
	count_mapped_characters(game, &p_count, &e_count);
	if (p_count > 1 || e_count > 1)
		error_exit(-2, "Invalid map: duplicate character", game, 0);
	if (game->c_count == 0)
		error_exit(-2, "Invalid map: collectibles not found", game, 0);
	if (p_count == 0)
		error_exit(-2, "Invalid map: player not found", game, 0);
	if (e_count == 0)
		error_exit(-2, "Invalid map: Exit not found", game, 0);
	game->cur_pos = game->start;
	path = valid_path(game->map, game->start, (t_path){0, 0});
	if (path.cltbl != game->c_count)
		error_exit(-2, "Invalid map: collectible not accessible", game, 0);
	if (path.found < 1)
		error_exit(-2, "Invalid map: no valid path", game, 0);
}

void	get_map_dimension(int fd, t_game *game)
{
	char	*str;

	game->m_rows = 0;
	game->m_cols = 0;
	str = get_next_line(fd);
	if (str != NULL)
		game->m_cols = ft_strlen(str) - 1;
	while (str != NULL)
	{
		game->m_rows++;
		free(str);
		str = get_next_line(fd);
		if ((str != NULL) && (game->m_cols < (int)(ft_strlen(str) - 1)))
			error_exit(fd, "Invalid map: not rectangular", NULL, 0);
	}
	if (game->m_cols == 0)
		error_exit(fd, "Empty map", NULL, 0);
}
