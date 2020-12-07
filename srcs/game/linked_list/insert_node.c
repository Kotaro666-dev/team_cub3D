/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:08:29 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/07 12:38:31 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_sprite.h"
#include "linked_list.h"
#include <stdlib.h>
#include "constants.h"
#include <stdio.h>

void		insert_node(int map_id)
{
	t_sprite_list	*new_node;

	new_node = (t_sprite_list*)malloc(sizeof(t_sprite_list));
	if (new_node == NULL)
	{
		perror("ERROR");
		clear_all_nodes();
		exit(ERROR);
	}
	new_node->data.map_id = map_id;
	new_node->data.is_first_hit = TRUE;
	new_node->next = g_nil->next;
	g_nil->next->prev = new_node;
	g_nil->next = new_node;
	new_node->prev = g_nil;
}
