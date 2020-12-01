/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:50:46 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/01 18:31:40 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_sprite.h"
#include "linked_list.h"
#include <stdlib.h>

void		clear_all_node(void)
{
	t_sprite_list	*current;
	t_sprite_list	*current_next;

	current = g_nil->next;
	while (current != g_nil)
	{
		current_next = current->next;
		free(current);
		current = current_next;
	}
	free(g_nil);
	g_nil = NULL;
}
