/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:00:10 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/20 14:01:36 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	main()
{
	t_game	*game;
	
	game = init_game();
	if (!game)
		return(1);
	if (init_graphics(game, "Cube3D") == NULL)
		error_handle1(game);
	printf("cur_pos is %d\n",grid_value(game->map, 0,0));
	
	free1(game);
	return (0);
}
