/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:21:42 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/18 15:40:32 by rnakai           ###   ########.fr       */
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

# define ROW 100
# define COL 100
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

# define ONCE 1

/*
** VALIDATE_MAP_UTILS.C
*/

# define TARGET "0-"

/*
** FOR RENDERING
*/

# define SPACE 0
# define WALL 1
# define SPRITE 2

# define PI 3.14159265
# define TWO_PI 6.28318530


/*
** tile size per one array element
*/

# define TILE_SIZE 32


/*
** map size (array size)
*/

# define ROWS 13
# define COLS 20


/*
** window width and height
*/

# define WIDTH 1980
# define HEIGHT 1080


/*
** minimap scale factor
*/

# define MAP_SCALE 0.3


/*
** actual map size (pixel)
*/

# define MAP_WIDTH (COLS * TILE_SIZE)
# define MAP_HEIGHT (ROWS * TILE_SIZE)

# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))

# define FOV_ANGLE (60 * (PI / 180))

# define NUM_RAYS WIDTH

#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

#define CLR_WHITE 0xFFFFFF
#define CLR_GRAY 0xCCCCCC
#define CLR_BLACK 0x000000
#define CLR_RED 0xFF0000
#define CLR_CEIL 0x95C0EC
#define CLR_FLOOR 0xCD8500

#endif