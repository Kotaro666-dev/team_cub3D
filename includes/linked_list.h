/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:39:21 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/01 13:26:34 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

#include "struct_sprite.h"

extern t_sprite_list	*g_nil;
extern t_sprite			g_sprite;

void			swap_node(t_sprite_list *fmr, t_sprite_list *ltr);
void			sort_node(void);
void			init_node(void);
t_sprite_data	*get_element_by_id(int map_id);
t_sprite_list	*get_first_element(void);
t_sprite_list	*get_nil(void);
void			insert_node(int map_id);
void			clear_all_node(void);
void			create_element(int map_id);

#endif
