/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:31:08 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/25 15:11:00 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "struct_rect_line.h"
# include "struct_game.h"
# include "struct_info.h"
# include <stdint.h>
# include "struct_3d_projection.h"
# include "struct_texture.h"
# include "struct_sprite.h"

extern char		g_map[ROW + 1][COL + 1];
extern int		g_is_game_running;
extern t_info	g_info;
extern t_player	g_player;
extern t_ray	*g_rays;
extern t_texture	g_textures[TEXTURE_NUM];
extern t_sprite	g_sprite;

/*
** my drawing functions
*/

void			my_mlx_pixel_put(t_game *game, int x, int y, uint32_t color);
void			draw_line
				(t_game *game, t_line_info line, uint32_t color);
void			draw_player_rect(t_game *game, t_rect_info rect, uint32_t color);


/*
** draw_2Dmap utils (from 42seoul git hub)
*/

void			draw_horizontal_lines(t_game *game);
void			draw_vertical_lines(t_game *game);
void			draw_rectangle(t_game *game, int x, int y, uint32_t color);
void			draw_rectangles(t_game *game);


/*
** functions: init rect, line struct easily
*/

t_rect_info		init_rect_info(int x, int y, int width, int height);
t_line_info		init_line_info(double x1, double y1, double x2, double y2);
void			init_sprite_info(void);


/*
** render_functions
*/

void			render_player(t_game *game);
void			render_rays(t_game *game);
void			render_map(t_game *game);
void			render_background(t_game *game);
void			render_3d_walls(t_game *game);
void			render_sprite(t_game *game);
void			render(t_game *game);
void			set_3d_wall_info(t_game *game, t_3d_prj *pj, int i);
void			store_textures(t_game *game);
uint32_t		get_texel_color(t_3d_prj *pj, int i, int tex_idx);
int				get_texture_orient_index(int i);
void			set_texture_offset_x(t_3d_prj *pj, int i, int tex_idx);


/*
** hook functions
*/

int				key_pressed(int key_code, t_game *game);
int				key_released(int key_code, t_game *game);
int				close_window(t_game *game);
void			register_hook(t_game *game);


/*
** system utility func
*/

int				has_wall_at(float x, float y);
int				has_sprite_at(float x, float y);
float			convert_orient_ch2angle(char orient);
void			convert_ch2num_map(char dst[ROW + 1][COL + 1],
					char src[ROW + 1][COL + 1]);
int				to_coord(int x, int y);
float			normalize_angle(float ray_angle);
void			print_debug_info_in_game(t_game *game);


/*
** game start functions
*/

void			start_play_mode(t_game *game);
void			start_save_mode(t_game *game);
void			initialize_window(t_game *game);
void			setup(t_game *game);
int				main_loop(t_game *game);


/*
** game update functions
*/

void			update(void);
void			cast_rays(void);
void			move_player(void);

#endif
