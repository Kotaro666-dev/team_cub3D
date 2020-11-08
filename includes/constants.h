/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:21:42 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/08 17:53:34 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

/*
** GENERAL MACRO
*/

# define TRUE 1
# define FALSE 0
# define ERROR -1

/*
** MAP
** IT WILL CAUSE SEGMENTAION FAULT WITH MORE THAN 400 ARRAY SIZE
*/

# define ROW 600
# define COL 600
# define ARR_SIZE 1000

/*
** MAIN
*/

# define SAVE_COMMAND "--save"
# define ERROR_MSG "Error"

/*
** VALIDATE MAP MACRO
*/

# define OUTER_WALL 'X'
# define INNER_SPACE '-'
# define PAINT 'p';
# define DIFF_X 2
# define DIFF_Y 2

/*
** PARSE_RESOLUTION_DATA
*/

#define LL long long int

/*
** READ_CUB_FILE_UTILS
*/

#define ONCE 1

/*
** VALIDATE_MAP_UTILS.C
*/

#define TARGET "0-X"

/*
** FOR RENDERING
*/

#define PI 3.14159265
#define TWO_PI 6.28318530

#define TILE_SIZE 64
#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20

#define MINIMAP_SCALE_FACTOR 0.2

#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

#define FOV_ANGLE (60 * (PI / 180))

#define NUM_RAYS WINDOW_WIDTH

#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

#define CLR_WHITE 0xFFFFFF
#define CLR_GRAY 0xCCCCCC
#define CLR_BLACK 0x000000
#define CLR_RED 0xFF0000
#define CLR_CEIL 0x95C0EC
#define CLR_FLOOR 0xCD8500

#endif