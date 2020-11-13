/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:25:30 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/13 18:17:36 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../definitions.h"
#include "../../includes/structs/struct_game.h"

void		register_hook(t_game *game)
{
	mlx_hook(game->win, X_EVENT_KEY_PRESS, KEY_PRESS_MASK, &key_pressed, game);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, KEY_RELEASE_MASK, &key_released, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, STRUCTURE_NOTIFY_MASK, &close, game);
	//focus in イベント（最小化してもう一度画面を戻すとき）が発生したときに再度描画するhookを登録する必要がある. linux vmで要検証。mlx_put_image_to_windowを呼び出して再描画させればよさげ
	mlx_loop_hook(game->mlx, &main_loop, game);
}
