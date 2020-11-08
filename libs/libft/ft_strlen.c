/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:19:44 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/24 23:56:45 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	if (s == NULL)
	{
		return (0);
	}
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
