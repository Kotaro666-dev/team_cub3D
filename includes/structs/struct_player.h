/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_player.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:37:22 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/28 20:41:19 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PLAYER_H
# define STRUCT_PLAYER_H

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction; // -1 for left, +1 for right
	int		walk_direction; // -1 for back, + 1 for forward
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
}				t_player;

#endif