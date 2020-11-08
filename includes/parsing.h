/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:18:22 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/28 20:34:07 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"
# include "utilities.h"
# include "./structs/struct_game.h"

int	parse_resolution_data(char **data, t_game *game);
int	parse_texture_data(char **data, t_game *game);
int	parse_color_data(char **data, t_game *game);

#endif
