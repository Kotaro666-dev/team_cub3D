/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:41:21 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/01 13:26:34 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_sprite.h"
#include "linked_list.h"
#include "constants.h"

void		create_element(int map_id)
{
	t_sprite_list	*current;

	current = g_nil->next;
	while (current != g_nil)
	{
		if (current->data.map_id == map_id)
			return ;
		current = current->next;
	}
	insert_node(map_id);
}
