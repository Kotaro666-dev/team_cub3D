/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:15:10 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/08 22:16:42 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "struct_game.h"
# include "struct_cub_elems.h"
# include "struct_error_msg.h"

/*
** CONVERT_RGB_TO_HEX.C
*/

void	convert_rgb_to_hex(t_cub_elems *cub_elems);

/*
** DICIDE_WHICH_MODE_TO_START.C
*/

int		should_write_bmp_image(char **argv);

/*
** INIT_STRUCTS.C
*/

void	init_cub_elems(t_cub_elems *cub_elems);

/*
** PRINT_ERR_MSG_C
*/

int		print_error_msg(t_err_msg *err_msg);

/*
** READ_CUB_FILES_UTILS.C
*/

int		err_action_with_free(t_game *game);
int		did_reach_eof(t_game *game);
int		can_start_reading_map(t_cub_elems *cub_elems);
int		have_you_seen_any_elemets(t_cub_elems *cub_elems);
int		did_collect_all_must_data(t_cub_elems *cub_elems);

/*
** READ_CUB_FILES_UTILS.C
*/

void	store_player_data(t_cub_elems *cub_elems, int pos_x, char orient);
void	update_max_x_on_map(t_cub_elems *cub_elems, int x);
int		have_already_found_map(t_map_data *map_data);
int		have_already_found_player(t_cub_elems *cub_elems);

/*
** USEFUL_FUNCS.C
*/

int		ft_strcmp(char *s1, char *s2);
int		is_file_extention_valid(char *file, char *extension);
void	free_memory_2d_array(char **line);
void	free_mlx_ptr(t_game *game);
void	free_memory(char *str);

/*
** VALIDATE_MAP_UTILS.C
*/

void	flood_fill(t_game *game, int y, int x, int *is_safe);
void	create_box_for_flood_map(t_cub_elems *cub_elems);

/*
** VALIDATE_CUB_FILE_UTILS.C
*/

int		does_len_array_match(char **color_data, int valid_len);
int		does_target_have_only_digits(char *str);
int		can_open_the_file(char *id, t_cub_elems *cub_elems);
int		is_texture_extension_valid(char *id, t_cub_elems *cub_elems);

#endif
