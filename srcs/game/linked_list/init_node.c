/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:36:30 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/07 11:20:30 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_sprite.h"
#include "linked_list.h"
#include <stdlib.h>
#include "constants.h"
#include <stdio.h>

void		init_node(void)
{
	g_nil = (t_sprite_list*)malloc(sizeof(t_sprite_list));
	if (g_nil == NULL)
	{
		perror("ERROR");
		clear_all_nodes();
		exit(ERROR);
	}
	g_nil->next = g_nil;
	g_nil->prev = g_nil;
}
