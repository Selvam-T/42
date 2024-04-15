/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:18:16 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/05 19:46:40 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

static void	init_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->m_rows)
	{
		game->map[i] = NULL;
		i++;
	}
}

static void	make_map(int fd, t_game *game)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	game->map = malloc(sizeof(t_map *) * game->m_rows);
	if (game->map == NULL)
		error_exit(-1, "Malloc", NULL, 1);
	init_map(game);
	while (i < game->m_rows)
	{
		game->map[i] = malloc(sizeof(t_map) * game->m_cols);
		if (game->map[i] == NULL)
			error_exit(-1, "Malloc", game, 1);
		str = get_next_line(fd);
		j = 0;
		while (j < game->m_cols)
		{
			game->map[i][j].c = str[j];
			game->map[i][j].v = 0;
			j++;
		}
		free(str);
		i++;
	}
}

void	free_map(t_map **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (map[i] != NULL)
			free(map[i]);
		i++;
	}
	free(map);
}

void	error_exit(int fd, char *str, t_game *game, int p_err)
{
	write(1, "Error\n", 6);
	if (fd > 0)
		close(fd);
	if (game != NULL)
		free_map(game->map, game->m_rows);
	if (p_err)
		perror(str);
	else
	{
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
	exit(EXIT_FAILURE);
}

void	get_map(char *mapfile, t_game *game)
{
	int		fd;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		error_exit(-1, "Open", NULL, 1);
	get_map_dimension(fd, game);
	close(fd);
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		error_exit(-1, "Open", NULL, 1);
	make_map(fd, game);
	validate_map(game);
	close(fd);
}
