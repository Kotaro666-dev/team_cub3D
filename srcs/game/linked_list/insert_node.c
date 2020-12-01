/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:08:29 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/01 12:31:41 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_sprite.h"
#include "linked_list.h"
#include <stdlib.h>
#include "constants.h"

void		insert_node(int map_id)
{
	t_sprite_list	*x;

	x = (t_sprite_list*)malloc(sizeof(t_sprite_list));
	x->data.map_id = map_id;
	x->data.is_first_hit = TRUE;

	x->next = g_nil->next;
	g_nil->next->prev = x;
	g_nil->next = x;
	x->prev = g_nil;
}
