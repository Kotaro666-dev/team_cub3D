/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:15:56 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/17 19:39:16 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLERS_H
# define CONTROLLERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "struct_game.h"
#include "linked_list.h"

int		decide_which_mode_to_start(int argc, char **argv, t_game *game);
int		read_cub_file(t_game *game);
int		parse_cub_elems(char **data, t_game *game);
int		validate_map(t_game *game);
int		read_cub_map(char **line, t_game *game);

#endif
