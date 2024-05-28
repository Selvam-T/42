/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:58:14 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/28 12:58:57 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"


int	camera_plane_vector()
{
	//player_position + direction + || - plane
}

int	direction_ray()
{
	//direction_vector() + %(camera_plane_vector())
}

int	direction_vector()
{
	//int	direction;
	//cell(x0,y0) --> position of a player
	//N = (0, -1); S = (0, 1); E = (1, 0); W = (-1, 0) --> player looking direction
	//direction = player's looking direction + x coordinate on screen
	
}

int	distance()
{
	//distance between hit point to the player position
}

int	wall_height()
{
	//based on the distance
	//farther away, smaller wall
	//nearer , higher wall
}

int	square_hit()
{
	//DDA algorithm --> which square on grid a line hits
	//uses direction_ray() + X and Y components of direction_vector()
}

int	find_wall()//along a pixel on horizontal plane
{
	//this loop is not across a camera plane, it is along a single ray
	//loop(until hit wall)-->increment position in direction()
	//start player position
	//if cell is 1, then wall = cell
	//end loop
	//distance = distance()
	//height = wall_height()
	//draw_wall()
}

int	fov()
{
	//angle between direction_ray(left_most) and direction_ray(right_most)
	//if direction_ray(left_most) == camera_plane_vector()
	//	fov = 90 deg
	//so if we take fov = 66 deg, then what are the other 2 components?
	//alternatively, fov = length of direction and the length of camera plane
	//fov = 2 * atan(0.66/1.0) = 66 deg
}

int	player_rotates()
{
	//when player rotates 
	// direction vertor and plane vector have to be rotated
	// multiply with rotation matrix
}


