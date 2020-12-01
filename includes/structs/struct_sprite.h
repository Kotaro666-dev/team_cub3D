/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_sprite.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:38:55 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/01 10:29:22 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SPRITE_H
# define STRUCT_SPRITE_H

typedef struct
{
	int			map_id; //map idx y * COL + map idx xで一意の値を得られる
	int			x; //spriteのx座標。
	int			y; 
	float		distance_to_center; //spriteとプレイヤーの距離
	int			is_first_hit;
	float		left_pos_from_center; //中央から見た、左端の位置。 
	float		right_pos_from_center; //右側の位置。
	int			left_edge_on_win; //window上の左端の位置。g_rays[i]のiで記録できる
	int			right_edge_on_win;
}		t_sprite_data;

typedef struct s_sprite_list
{
	t_sprite_data			data;
	struct s_sprite_list	*next;
	struct s_sprite_list	*prev;
}		t_sprite_list;

typedef struct
{
	void			(*init)(void);
	void			(*clear)(void);
	void			(*create_elem)(int);
	t_sprite_data	*(*get_elem_by_id)(int);
	void			(*insert)(int);
	t_sprite_list	*(*get_1st_elem)(void);
	t_sprite_list	*(*get_nil)(void);
	void			(*swap)(t_sprite_list*, t_sprite_list*);
	void			(*sort)(void);
}		t_sprite

#endif
