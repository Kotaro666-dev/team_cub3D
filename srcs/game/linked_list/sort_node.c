/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:26:42 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/01 18:08:10 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_sprite.h"
#include "linked_list.h"
#include "constants.h"

void		sort_node(void)
{
	t_sprite_list	*head;
	t_sprite_list	*current;

	head = g_nil->next;
	while (head->next != g_nil)
	{
		current = head->next;
		while (current != g_nil)
		{
			if (head->data.distance_to_center <
				current->data.distance_to_center)
				swap_node(head, current);
			current = current->next;
		}
		head = head->next;
	}
}
