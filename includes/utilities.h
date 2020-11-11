/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:15:10 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/11 10:48:43 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "./structs/struct_game.h"
# include "./structs/struct_map_data.h"
# include "./structs/struct_error_msg.h"

/*
** CREATE_RECTANGLAR_MAP.C
*/

void	create_rectanglar_map(t_game *game);

/*
** DEBUG_FUNCS.C
*/

void	show_cub_data_for_debug(t_cub_data *cub_data);
void	debug_flood_fill_before(t_cub_data *cub_data);
void	debug_flood_fill_after(t_cub_data *cub_data);
void	debug_rectanglar_map(t_game *game);

/*
** INIT_STRUCTS.C
*/

void	init_cub_data(t_cub_data *cub_data);

/*
** PRINT_ERR_MSG_C
*/

int		print_error_msg(t_err_msg *err_msg);

/*
** READ_CUB_FILES_UTILS.C
*/

int		can_start_reading_map(t_cub_data *cub_data);
int		should_ignore_empty_line(char **line);
int		did_collect_all_must_data(t_cub_data *cub_data);

/*
** USEFUL_FUNCS.C
*/

int		ft_strcmp(char *s1, char *s2);
void	free_memory_of_2d_array(char **line);
void	free_memory(char *str);

/*
** VALIDATE_MAP_UTILS.C
*/

void	flood_fill(t_cub_data *cub_data, int y, int x, int *is_safe);
void	create_box_for_flood_map(t_cub_data *cub_data);

/*
** VALIDATE_CUB_FILE_UTILS.C
*/

int		is_len_of_data_valid(char **color_data, int valid_len);
int		is_data_unsigned_integer(char *str);
int		is_ext_xpm(char *file);
int		can_open_the_file(char *id, t_cub_data *cub_data);
int		is_tex_ext_valid(char *id, t_cub_data *cub_data);

/*
** USEFUL_RENDER_FUNCS.C
*/

int		has_wall_at(t_cub_data *cub_data,float x, float y);
float	normalize_angle(float ray_angle);
float	distance_between_points(float x1, float y1, float x2, float y2);

#endif
