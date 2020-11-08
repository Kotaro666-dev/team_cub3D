/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:00:22 by kkamashi          #+#    #+#             */
/*   Updated: 2020/07/01 19:34:09 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;

	if ((*f) == NULL || (*del) == NULL)
	{
		return (NULL);
	}
	new_list = NULL;
	while (lst != NULL)
	{
	}
	return (new_list);
}
