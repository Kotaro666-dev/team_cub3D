/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:26:05 by kkamashi          #+#    #+#             */
/*   Updated: 2020/07/01 19:14:34 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dst_len;
	size_t		src_len;
	size_t		index_dst;
	size_t		index_src;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	index_dst = dst_len;
	index_src = 0;
	if (dstsize > 0 && dst_len < dstsize - 1)
	{
		while (src[index_src] != '\0')
		{
			dst[index_dst++] = src[index_src++];
			if (index_src == dstsize - dst_len - 1)
				break ;
		}
		dst[index_dst] = '\0';
	}
	else if (dstsize == 0 || dst_len >= dstsize)
	{
		dst_len = dstsize;
	}
	return (dst_len + src_len);
}
