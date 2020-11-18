/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:31:08 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/18 12:47:55 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "struct_rect_line.h"
# include "struct_game.h"

extern int		g_map[ROWS][COLS];
extern int		g_is_game_running;
extern int		g_key_flag;
extern t_player	g_player;
extern t_ray	g_rays[NUM_RAYS];

/*
** my drawing functions
*/

void			my_mlx_pixel_put(t_game *game, int x, int y, int color);
void			draw_line
				(t_game *game, t_line_info line, int color);
void			draw_player_rect(t_game *game, t_rect_info rect, int color);


/*
** draw_2Dmap utils (from 42seoul git hub)
*/

void			draw_horizontal_lines(t_game *game);
void			draw_vertical_lines(t_game *game);
void			draw_rectangle(t_game *game, int x, int y, int color);
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


/*
** hook functions
*/

int				key_pressed(int key_code, t_game *game);
int				key_released(int key_code, t_game *game);
int				close_window(t_game *game);
void			register_hook(t_game *game);


/*
** utility func
*/

int				has_wall_at(float x, float y);


/*
** game start functions
*/

void			start_game(t_game *game);
void			initialize_window(t_game *game);
void			setup(void);
int				main_loop(t_game *game);


/*
** game update functions
*/

void			update(void);
void			cast_rays(void);
void			move_player(void);

#endif
