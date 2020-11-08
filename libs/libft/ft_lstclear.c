/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 10:51:07 by kkamashi          #+#    #+#             */
/*   Updated: 2020/07/01 15:13:51 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_one;

	if (lst == NULL || (*del) == NULL)
	{
		return ;
	}
	while (*lst != NULL)
	{
		next_one = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_one;
	}
}
