/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:21:42 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/08 20:00:00 by kkamashi         ###   ########.fr       */
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

# define ROW 200
# define COL 200
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
** FILE EXTENSION
*/

# define DOT_CUB ".cub"
# define DOT_XPM ".xpm"

/*
** VALIDATE MAP MACRO
*/

# define OUTER_WALL 'X'
# define INNER_SPACE '-'
# define PAINT 'p'
# define DIFF_X 2
# define DIFF_Y 2

/*
** PARSE_RESOLUTION_DATA
*/

# define LL long long int
# define INT_OVERFLOW_VALUE -1

/*
** PARSE_CUB_ELEMS
*/

# define SKIP 1

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

# define TILE_SIZE_RACIO ((float)32 / TILE_SIZE)
# define COL_RACIO ((float)50 / COL)
# define ROW_RACIO ((float)50 / ROW)

/*
** MINIMAP SCALE FACTOR
*/

# define MAP_SCALE (0.4 * TILE_SIZE_RACIO * COL_RACIO * ROW_RACIO)

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

/*
** RAY CASTING DETECTING MODE FLAG
*/

# define DETECTING_WALLS 413
# define DETECTING_SPRITE 414

/*
** SET SPRITE DATA MARGIN OF ERROR
*/

# define MARGIN 0.1

#endif
