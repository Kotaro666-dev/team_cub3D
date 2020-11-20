/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:31:08 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/20 17:05:27 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "struct_rect_line.h"
# include "struct_game.h"
# include "struct_info.h"
# include <stdint.h>

extern char		g_map[ROW + 1][COL + 1];
extern int		g_is_game_running;
extern t_info	g_info;
extern t_player	g_player;
extern t_ray	*g_rays;

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
void			set_accurate_texture(t_game *game, t_3d_prj *pj, int i);


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
float			convert_orient_ch2angle(char orient);
void			convert_ch2num_map(char dst[ROW + 1][COL + 1],
					char src[ROW + 1][COL + 1]);
int				to_coord(int x, int y);


/*
** game start functions
*/

void			start_game(t_game *game);
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
