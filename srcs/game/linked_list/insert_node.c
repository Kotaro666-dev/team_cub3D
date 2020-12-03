/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:08:29 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/03 11:05:39 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_sprite.h"
#include "linked_list.h"
#include <stdlib.h>
#include "constants.h"

void		insert_node(int map_id)
{
	t_sprite_list	*new_node;

	new_node = (t_sprite_list*)malloc(sizeof(t_sprite_list));
	new_node->data.map_id = map_id;
	new_node->data.is_first_hit = TRUE;

	new_node->next = g_nil->next;
	g_nil->next->prev = new_node;
	g_nil->next = new_node;
	new_node->prev = g_nil;
}
