/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:15:56 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/14 22:20:13 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLERS_H
# define CONTROLLERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"
# include "structs/struct_game.h"

int		handle_command_line(int argc, char **argv, t_game *game);
int		read_cub_file(t_game *game);
int		parse_cub_elems(char **data, t_game *game);
int		check_contents_in_line(char *line, t_cub_data *cub_data);
int		validate_map(t_game *game);

#endif
