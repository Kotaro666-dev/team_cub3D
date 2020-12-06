/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_player.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:37:22 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/04 15:46:50 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PLAYER_H
# define STRUCT_PLAYER_H

/*
** 	int		turn_direction; // -1 for left, +1 for right
** 	int		walk_direction; // -1 for back, + 1 for forward
** 	float	side_angle; //-1 for left, +1 for right
*/

typedef struct	s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction;
	int		walk_direction;
	float	side_angle;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
}				t_player;

#endif
