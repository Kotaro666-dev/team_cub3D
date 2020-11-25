/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_save_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:39:13 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/25 13:06:57 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "game.h"
#include "mlx.h"
#include "bmp.h"

void	start_save_mode(t_game *game)
{
	render_image_for_bmp(game);
	if (create_bmp_file(game) == ERROR)
	{
		print_error_msg(&game->err_msg);
	}
	free_mlx_ptr(game);
	exit(0);
}
