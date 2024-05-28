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
	
	printf("The tangent of 0.66 is %.2f\n",tan(0.66));
	game = init_game();
	if (!game)
		return(1);
	create_img(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_hook(game->win, 17, 0, &exit_game, &game);
	mlx_loop(game->mlx);
	free3(game);
	return (0);
}

//mlx_clear_window(t_xvar *xvar,t_win_list *win)
//int	mlx_destroy_display(t_xvar *xvar)
//int	mlx_destroy_image(t_xvar *xvar, t_img *img)
//int	mlx_destroy_window(t_xvar *xvar,t_win_list *win)

//char	*mlx_get_data_addr(t_img *img,int *bits_per_pixel, int *size_line,int *endian)

//int mlx_key_hook(t_win_list *win,int (*funct)(),void *param)
//int	mlx_loop_hook(t_xvar *xvar,int (*funct)(),void *param)
//void	*mlx_new_image(t_xvar *xvar,int width, int height)
//int	mlx_put_image_to_window(t_xvar *xvar,t_win_list *win,t_img *img, int x,int y)

//int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey)
//int		mlx_string_put(t_xvar *xvar,t_win_list *win, int x,int y,int color,char *string)
