/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:10:16 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/04 12:49:09 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_sprite.h"
#include "linked_list.h"
#include "game.h"

void		g_sprite_constructor(void)
{
	g_sprite.init = init_node;
	g_sprite.clear = clear_all_nodes;
	g_sprite.create_elem = create_element;
	g_sprite.get_elem_by_id = get_element_by_id;
	g_sprite.insert = insert_node;
	g_sprite.get_1st_elem = get_first_element;
	g_sprite.get_nil = get_nil;
	g_sprite.swap = swap_node;
	g_sprite.sort = sort_node_list;
}