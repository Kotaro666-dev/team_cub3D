/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:20:58 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/01 13:18:21 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_sprite.h"
#include "linked_list.h"
#include <stdlib.h>
#include "constants.h"

t_sprite_data	*get_element_by_id(int map_id)
{
	t_sprite_list	*current;

	current = g_nil->next;
	while (current != g_nil)
	{
		if (current->data.map_id == map_id)
			return (&current->data);
		current = current->next;
	}
	return (NULL);
}

t_sprite_list	*get_first_element(void)
{
	return (g_nil->next);
}

t_sprite_list	*get_nil(void)
{
	return (g_nil);
}
