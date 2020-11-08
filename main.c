/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:17:06 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/08 20:50:22 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/keys.h"
#include "includes/controllers.h"
#include "includes/structs/struct_game.h"
#include "includes/utilities.h"
#include "includes/constants.h"


/*
** ここの箇所は読み込んだマップを描写するテストコード
** のちほど削除しても問題なし
*/
void	image_init(t_game *game)
{
	game->image.img = mlx_new_image(game->mlx, game->cub_data.rez.width, game->cub_data.rez.height);
	game->image.buffer = (int *)mlx_get_data_addr(game->image.img, &game->image.bpp, &game->image.size_line, &game->image.endian);
	game->image.bpp = 32;
	game->image.size_line /= 4;
}

void	create_image(t_game *game)
{
	int size_col;
	int size_row;

	size_col = 20;
	for(int y = 0; y < game->cub_data.rez.height; ++y)
	{
		for(int x = 0; x < game->cub_data.rez.width; ++x)
		{
			int div_col = game->cub_data.rez.height / size_col;
			size_row = (int)ft_strlen(game->cub_data.map_data.map[y / div_col]);
			int div_row = game->cub_data.rez.width / size_row;
			div_col *= MINIMAP_SCALE_FACTOR;
			div_row *= MINIMAP_SCALE_FACTOR;
			if (game->cub_data.map_data.map[y / div_col][x / div_row] == '1')
			{
				game->image.buffer[(y * game->image.size_line) + x] = CLR_BLACK;
			}
			// floors
			else if (game->cub_data.map_data.map[y / div_col][x / div_row] == '0')
			{
				game->image.buffer[(y * game->image.size_line) + x] = CLR_WHITE;
			}
			// player
			else if (game->cub_data.map_data.map[y / div_col][x / div_row] == game->cub_data.map_data.player_orient)
			{
				game->image.buffer[(y * game->image.size_line) + x] = CLR_RED;
			}
			else
			{
				game->image.buffer[(y * game->image.size_line) + x] = CLR_GRAY;
			}
		}
	}
}

int		main_loop(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->image.img, 0, 0);
	create_image(game);
	return (0);
}

/*
** ここまで
*/

int main(int argc, char **argv)
{
	t_game			game;

	game.mlx = mlx_init();
	init_cub_data(&game.cub_data);
	mlx_get_screen_size(game.mlx, &game.cub_data.rez.my_width, &game.cub_data.rez.my_height);
	game.should_game_start = handle_command_line(argc, argv, &game);
	if (game.should_game_start == ERROR)
	{
		return (1);
	}
	game.win = mlx_new_window(game.mlx, game.cub_data.rez.width, game.cub_data.rez.height, "cub3D");
	image_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game.mlx);
	mlx_hook(game.win, 17, 1L<<17, close_window, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
