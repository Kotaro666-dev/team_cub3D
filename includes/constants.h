/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:21:42 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/26 18:58:29 by rnakai           ###   ########.fr       */
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
*/

# define ROW 50
# define COL 50
# define ARR_SIZE 1000

/*
** MAIN
*/

# define SAVE_COMMAND "--save"
# define ERROR_MSG "Error"
# define PLAY_MODE 2
# define SAVE_MODE 3
# define SUCCESS 0

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

# define TARGET "02-"

/*
** FOR RENDERING
*/

# define SPACE 0
# define WALL 1
# define SPRITE 2

# define PI 3.14159265
# define TWO_PI 6.28318530


/*
** TILE SIZE PER ONE ARRAY ELEMENT
*/

# define TILE_SIZE 64

# define DEFAULT_TILE_SIZE_RACIO ((float)32 / TILE_SIZE)
# define DEFAULT_COL_RACIO ((float)50 / COL)
# define DEFAULT_ROW_RACIO ((float)50 / ROW)


/*
** useful macro
*/

# define MAX(x, y) (x > y) ? x : y
# define MIN(x, y) (x < y) ? x : y

/*
** MINIMAP SCALE FACTOR
*/

# define MAP_SCALE (0.4 * DEFAULT_TILE_SIZE_RACIO * DEFAULT_COL_RACIO * DEFAULT_ROW_RACIO)


/*
** ACTUAL MAP SIZE (PIXEL)
*/

# define MAP_WIDTH (COL * TILE_SIZE)
# define MAP_HEIGHT (ROW * TILE_SIZE)

# define FOV_ANGLE (60 * (PI / 180))


/*
** TEXTURE INDEX
*/

# define TEXTURE_NUM 5
# define NORTH_IDX 0
# define SOUTH_IDX 1
# define EAST_IDX 2
# define WEST_IDX 3
# define SPRITE_IDX 4

#define CLR_WHITE 0xFFFFFF
#define CLR_GRAY 0xCCCCCC
#define CLR_BLACK 0x000000
#define CLR_RED 0xFF0000
#define CLR_CEIL 0x95C0EC
#define CLR_FLOOR 0xCD8500

#endif