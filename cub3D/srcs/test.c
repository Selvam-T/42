/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:32:29 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/20 17:36:19 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

void	print_game(t_game *game)
{
	printf("map dimension x: %d, y: %d \n",game->dim.x, game->dim.y);
	printf("Player position x: %d, y: %d \n",game->pp.x, game->pp.y);
	printf("Direction vector x: %d, y: %d \n",game->dd.x, game->dd.y);

}
