/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:30:47 by kkamashi          #+#    #+#             */
/*   Updated: 2020/06/29 22:07:51 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str_dst;
	unsigned char	*str_src;
	size_t			i;

	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return (str_dst);
}
