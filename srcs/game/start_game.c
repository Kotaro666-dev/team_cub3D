/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:55:53 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/13 18:21:41 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs/struct_game.h"
#include "definitions.h"

void	initialize_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "mlx 42");
	game->image.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->image.buffer = (int *)mlx_get_data_addr(game->image.img, &game->image.bpp, &game->image.size_line, &game->image.endian);
	return (TRUE);
}

void	setup(void)
{
	g_player.x = WIDTH / 2;
	g_player.y = HEIGHT / 2;
	g_player.width = 5;
	g_player.height = 5;
	g_player.turn_direction = 0; //-1 if left, +1 if right
	g_player.walk_direction = 0; //-1 if back, +1 if front
	g_player.side_angle = 0;
	g_player.rotation_angle = PI / 2;
	g_player.walk_speed = 3;
	g_player.turn_speed = 10 * (PI / 180);
	g_key_flag = FALSE;
	// g_map = ...
}

int		main_loop(t_game *game)
{
	if (g_key_flag == TRUE)
	{
		//	描画する
		update();
		render(game);
	}
	g_key_flag = FALSE;
	return (0);
}

void	start_game(t_game *game)
{
	initialize_window(&game);
	setup(); //initializing by putting every global var
	register_hook(game); //calling main loop inside this func
	mlx_loop(game->mlx);
	mlx_destroy_image(game->mlx, game->image.img);
	mlx_destroy_window(game->mlx, game->image.img);
}