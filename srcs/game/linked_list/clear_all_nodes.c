/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:54:48 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/07 11:20:21 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_sprite.h"
#include "linked_list.h"
#include <stdlib.h>

void		clear_all_nodes(void)
{
	t_sprite_list	*current;
	t_sprite_list	*next;

	if (g_nil == NULL)
		return ;
	current = g_nil->next;
	while (current != g_nil)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(g_nil);
	g_nil = NULL;
}
