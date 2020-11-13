/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:14:37 by rnakai            #+#    #+#             */
/*   Updated: 2020/11/13 18:17:52 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include <math.h>
# include "../../minilibx-linux/mlx.h"
# include "../../includes/structs/struct_player.h"
# include "../../includes/structs/struct_ray.h"
# include "../../includes/structs/struct_rect_line.h"
#include "../../includes/structs/struct_game.h"

# define TRUE 1
# define FALSE 0

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17 //Exit program key code

# define KEY_PRESS_MASK			1<<0
# define KEY_RELEASE_MASK		1<<1
# define STRUCTURE_NOTIFY_MASK	1<<17

# define KEY_ESC				65307
# define KEY_W					119
# define KEY_A					97
# define KEY_S					115
# define KEY_D					100
# define KEY_LEFT_ARROW			65361
# define KEY_RIGHT_ARROW		65363

# define TILE_SIZE 32
# define ROWS 13
# define COLS 20
# define WIDTH (COLS * TILE_SIZE)
# define HEIGHT (ROWS * TILE_SIZE)
# define MINIMAP_SCALE_FACTOR 1

# define PI 3.14159265
# define TWO_PI 6.28318530

# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))

# define FOV_ANGLE (60 * (PI / 180))
# define NUM_RAYS WIDTH

# define SPACE 0
# define WALL 1
# define SPRITE 2

extern int		g_map[ROWS][COLS];
extern int		g_is_game_running;
extern int		g_key_flag;
extern t_player	g_player;
extern t_ray	g_rays[NUM_RAYS];

// typedef struct	s_img
// {
// 	void	*img;
// 	int		*data; //imgの本体

// 	int		size_l;
// 	int		bpp;
// 	int		endian;
// }				t_img;

// typedef struct	s_game
// {
// 	void	*mlx;
// 	void	*win;
// 	t_img	img;
// }				t_game;

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

void			draw_lines(t_game *game);
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
void			render(t_game *game);


/*
** hook functions
*/

int				key_pressed(int key_code, t_game *game);
int				key_released(int key_code, t_game *game);
int				close(t_game *game);
void			register_hook(t_game *game);


/*
** utility func
*/

int				has_wall_at(float x, float y);


/*
** game start functions
*/

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
